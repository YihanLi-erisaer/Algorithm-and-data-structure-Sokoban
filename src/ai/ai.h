#ifndef __AI__
#define __AI__

#include <stdint.h>
#include <unistd.h>
#include "node.h"
#include "priority_queue.h"

void solve(char const *path, bool show_solution);
void freeNode(node_t* node, sokoban_t* init_data);
#endif
