#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/* Defines the interface for modifying writable properties in controlled hardware.
   It is a tree structure provided by a module. */

enum tc_assignable_value_category {
  TC_ASSIGNABLE_RANGE,
  TC_ASSIGNABLE_ENUM
};

// Is the range double or integer
enum tc_assignable_range_data_type {
  TC_ASSIGNABLE_RANGE_INT,
  TC_ASSIGNABLE_RANGE_DOUBLE
};

typedef struct {
  double min, max;
} tc_assignable_range_double_t;

typedef struct {
  int64_t min, max;
} tc_assignable_range_int_t;

typedef struct {
  enum tc_assignable_range_data_type range_data_type;
  union {
    tc_assignable_range_double_t double_range;
    tc_assignable_range_int_t int_range;
  };
} tc_assignable_range_t;

typedef struct {
  uint16_t property_count;
  char **properties;
} tc_assignable_enum_t;

typedef struct tc_assignable_node_t {
  // Assignable name eg. fan speed
  char *name;
  // Unit for assignable
  char *unit;

  bool assignable;
  // Callback for assignment
  int8_t (*assign_callback)();

  // Possible values for tunables are either values from a range or enumerations
  enum tc_assignable_value_category value_category;
  union {
    tc_assignable_enum_t enum_info;
    tc_assignable_range_t range_info;
  };

  struct tc_assignable_node_t *parent;
  uint16_t children_count;
  struct tc_assignable_node_t **children_nodes;
} tc_assignable_node_t;

/* Utility functions for assignables */
// Allocates memory for a tunable node
tc_assignable_node_t *tc_assignable_node_new();
// Deallocates memory of the node
void tc_assignable_node_destroy(tc_assignable_node_t *node);

// Add a child to a node
int8_t tc_assignable_node_add_child(tc_assignable_node_t *node, tc_assignable_node_t *child);

/* Utility functions for range and property info*/

#ifdef __cplusplus
}
#endif