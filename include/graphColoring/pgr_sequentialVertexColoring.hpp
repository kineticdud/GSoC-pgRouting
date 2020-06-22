/*PGR-GNU*****************************************************************
File: pgr_sequentialVertexColoring.hpp

Copyright (c) 2020 pgRouting developers
Mail: project@pgrouting.org

Copyright (c) 2020 Ashish Kumar
Mail: ashishkr23438@gmail.com

------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
********************************************************************PGR-GNU*/

#ifndef INCLUDE_GRAPHCOLORING_PGR_SEQUENTIALVERTEXCOLORING_HPP_
#define INCLUDE_GRAPHCOLORING_PGR_SEQUENTIALVERTEXCOLORING_HPP_
#pragma once



#include <vector>
#include <map>

#include "cpp_common/pgr_base_graph.hpp"
#include "cpp_common/pgr_messages.h"


/** @file pgr_sequentialVertexColoring.hpp
 * @brief The main file which calls the respective boost function.
 *
 * Contains actual implementation of the function and the calling
 * of the respective boost function.
 */


namespace pgrouting {
namespace functions {

//*************************************************************

template <class G>
class Pgr_sequentialVertexColoring : public pgrouting::Pgr_messages {
public:
    typedef typename G::V V;
    typedef typename G::E E;

    /** @name SequentialVertexColoring
     * @{
     * 
     */

    /** @brief sequentialVertexColoring function
     *
     * It does all the processing and returns the results.
     *
     * @param graph      the graph containing the edges
     *
     * @returns results, when results are found
     *
     * @see [boost::sequential_vertex_coloring]
     * (https://www.boost.org/doc/libs/1_73_0/libs/graph/doc/sequential_vertex_coloring.html)
     */
    std::vector<pgr_vertex_color_rt> sequentialVertexColoring(
            G &graph) {
        std::vector<pgr_vertex_color_rt> results;



        return results;
    }

    //@}

};
}  // namespace functions
}  // namespace pgrouting

#endif  // INCLUDE_GRAPHCOLORING_PGR_SEQUENTIALVERTEXCOLORING_HPP_