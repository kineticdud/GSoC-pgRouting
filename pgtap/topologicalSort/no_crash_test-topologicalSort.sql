\i setup.sql

SELECT plan(5);

CREATE TABLE edge_table (
    id serial,
    source integer,
    target integer,
    cost double precision,
    reverse_cost double precision,
);
INSERT INTO edge_table (source,target,cost,reverse_cost) VALUES ( 1, 2,0,0);
INSERT INTO edge_table (cost,reverse_cost,x1,y1,x2,y2) VALUES (2,3,0,0);

SELECT has_function('pgr_topologicalSort');

SELECT function_returns('pgr_topologicalSort', ARRAY['text'], 'setof record');

-- flags
-- error
SELECT throws_ok(
    'SELECT * FROM pgr_topologicalSort(
        ''SELECT id, source, target, cost, reverse_cost FROM edge_table id < 17'',
        3
    )','42883','function pgr_topologicalSort(unknown, integer) does not exist',
    '6: Documentation says it does not work with 1 flags');


SELECT lives_ok(
    'SELECT * FROM pgr_topologicalSort(
        ''SELECT id, source, target, cost, reverse_cost FROM edge_table''
    )',
    '4: Documentation says works with no flags');


-- prepare for testing return types

PREPARE all_return AS
SELECT
    'integer'::text AS t1,
    'integer'::text AS t2;

PREPARE q1 AS
SELECT pg_typeof(seq)::text AS t1,
       pg_typeof(sorted_v)::text AS t2
    FROM (
        SELECT * FROM pgr_topologicalSort(
            'SELECT id, source, target, cost, reverse_cost FROM edge_table WHERE id < 17'
        ) ) AS a
    limit 1;


SELECT set_eq('q1', 'all_return', 'Expected returning, columns names & types');

SELECT * FROM finish();
ROLLBACK;