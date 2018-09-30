/*
 * Problem: https://leetcode.com/problems/surrounded-regions
 *
 * The idea is simple, the Os are vertices of the graph, neighboring Os form edges. Start BFS (can be DFS or whatever
 * doesn't matter) from all Os  of each edge of the board and mark all reached Os as Zs (or any other random char) on
 * the board. Then go through the board and flip Os (unreached vertices) to Xs and Zs (reached vertices) to Os.
 */

#include <vector>
#include <queue>

struct Vertex { // should i worry about visibility -- private/public/etc. of stuff?
    const size_t i, j;  // i don't know which type to use for the sizes, is vector<?>::size_type better?
    Vertex(const size_t i, const size_t j) : i(i), j(j) {}
};

inline void enqueueUnvisited(
        std::vector<std::vector<char>> &board,
        std::queue<Vertex> &bfsQ,
        const size_t &vi,
        const size_t &vj) {
    char &c = board[vi][vj];
    if (c == 'O') {
        bfsQ.emplace(vi, vj);
        c = 'Z';
    }
}

inline void bfs(
        std::vector<std::vector<char>> &board,
        std::queue<Vertex> &bfsQ,
        const size_t &i,
        const size_t &maxI,
        const size_t &j,
        const size_t &maxJ) {
    enqueueUnvisited(board, bfsQ, i, j);
    while (!bfsQ.empty()) {
        Vertex& v =  bfsQ.front();
        const size_t &vi = v.i;
        const size_t &vj = v.j;
        // v has 0 to 4 neighbours: up, down, left, right
        if (vi > 0) enqueueUnvisited(board, bfsQ, vi-1, vj);
        if (vi < maxI) enqueueUnvisited(board, bfsQ, vi+1, vj);
        if (vj > 0) enqueueUnvisited(board, bfsQ, vi, vj-1);
        if (vj < maxJ) enqueueUnvisited(board, bfsQ, vi, vj+1);
        bfsQ.pop();
    }
}

void xSurroundedRegions(std::vector<std::vector<char>> &board) {
    if (board.empty()) return;
    const size_t nRows = board.size();
    const size_t nCols = board[0].size();
    if (nCols == 0) return;
    const size_t maxI = nRows-1;
    const size_t maxJ = nCols-1;

    std::queue<Vertex> bfsQ;
    for (size_t i = 0, j = 0; i<nRows; i++) bfs(board, bfsQ, i, maxI, j, maxJ); // BFS from right edge
    for (size_t i = 0, j = maxJ; i<nRows; i++) bfs(board, bfsQ, i, maxI, j, maxJ); // BFS from left edge
    for (size_t i = 0, j = 0; j<nCols; j++) bfs(board, bfsQ, i, maxI, j, maxJ); // BFS from top edge
    for (size_t i = maxI, j = 0; j<nCols; j++) bfs(board, bfsQ, i, maxI, j, maxJ); // BFS from bottom edge

    // set unvisited -- Os to Xs; set visited -- Zs to Os
    for (size_t i = 0; i<nRows; i++) {
        for (size_t j = 0; j<nCols; j++) {
            char& c = board[i][j];
            if (c == 'O') c = 'X';
            else if (c == 'Z') c = 'O';
        }
    }
}