#include <stdio.h>
#include <assert.h>
//#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
//#include "libs/algorithms/array/array.h"
//#include "libs/data_structures/ordered_array_set/ordered_array_set.h"
//#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/vector/vector.h"

//void test_unordered_array_in1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    size_t resSet = unordered_array_set_in(set1, 3);
//    assert(resSet == 2);
//
//    unordered_array_set_delete(set1);
//}
//
//void test_unordered_array_in2() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    size_t resSet = unordered_array_set_in(set1, 1);
//    assert (resSet == 0);
//
//    unordered_array_set_delete(set1);
//}
//
//void test_unordered_array_set_in() {
//    test_unordered_array_in1();
//    test_unordered_array_in2();
//}
//
//void test_unordered_array_set_isSubset1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    bool resSet = unordered_array_set_isSubset(set1, set2);
//    assert (resSet == 0);
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//}
//
//void test_unordered_array_set_isSubset2() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2}, 1);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    bool resSet = unordered_array_set_isSubset(set1, set2);
//    assert (resSet == 1);
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//}
//
//void test_unordered_array_set_isSubset() {
//    test_unordered_array_set_isSubset1();
//    test_unordered_array_set_isSubset2();
//}
//
//void test_unordered_array_set_insert1() {
//    unordered_array_set set1 = unordered_array_set_create(3);
//
//    unordered_array_set_insert(&set1, 3);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {3}, 1);
//    assert (unordered_array_set_isEqual(set1, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_insert2() {
//    unordered_array_set set1 = unordered_array_set_create(3);
//
//    unordered_array_set_insert(&set1, 2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2}, 1);
//    assert (unordered_array_set_isEqual(set1, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(expectedSet);
//}
//
//
//void test_unordered_array_set_insert() {
//    test_unordered_array_set_insert1();
//    test_unordered_array_set_insert2();
//}
//
//void test_unordered_array_set_deleteElement1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    unordered_array_set_deleteElement(&set1, 2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1}, 1);
//    assert (unordered_array_set_isEqual(set1, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_deleteElement2() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    unordered_array_set_deleteElement(&set1, 1);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2}, 1);
//    assert (unordered_array_set_isEqual(set1, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_deleteElement3() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    unordered_array_set_deleteElement(&set1, 3);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    assert (unordered_array_set_isEqual(set1, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_deleteElement() {
//    test_unordered_array_set_deleteElement1();
//    test_unordered_array_set_deleteElement2();
//    test_unordered_array_set_deleteElement3();
//}
//
//void test_unordered_array_union1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    unordered_array_set resSet = unordered_array_set_union(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_union2() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
//    unordered_array_set resSet = unordered_array_set_union(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_union() {
//    test_unordered_array_union1();
//    test_unordered_array_union2();
//}
//
//
//void test_unordered_array_intersection1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2}, 1);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_intersection2() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
//    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {}, 0);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_intersection() {
//    test_unordered_array_intersection1();
//    test_unordered_array_intersection2();
//}
//
//void test_unordered_array_set_difference1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 4, 5}, 4);
//    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {3}, 1);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_difference2() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {}, 0);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_difference() {
//    test_unordered_array_set_difference1();
//    test_unordered_array_set_difference2();
//}
//
//void test_unordered_array_set_symmetricDifference1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 4, 5}, 4);
//    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {3, 4, 5}, 3);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_symmetricDifference2() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
//    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {4}, 1);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_symmetricDifference() {
//    test_unordered_array_set_symmetricDifference1();
//    test_unordered_array_set_symmetricDifference2();
//}
//
//void test_unordered_array_set_complement1() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
//    unordered_array_set resSet = unordered_array_set_complement(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {4}, 1);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_complement2() {
//    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
//    unordered_array_set resSet = unordered_array_set_complement(set1, set2);
//    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 4}, 2);
//    assert (unordered_array_set_isEqual(resSet, expectedSet));
//
//    unordered_array_set_delete(set1);
//    unordered_array_set_delete(set2);
//    unordered_array_set_delete(resSet);
//    unordered_array_set_delete(expectedSet);
//}
//
//void test_unordered_array_set_complement() {
//    test_unordered_array_set_complement1();
//    test_unordered_array_set_complement2();
//}
//
//
//void test_ordered_array_set_in1() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    size_t resSet = ordered_array_set_in(&set1, 3);
//    assert (resSet == 2);
//
//    ordered_array_set_delete(set1);
//}
//
//void test_ordered_array_set_in2() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    size_t resSet = ordered_array_set_in(&set1, 1);
//    assert (resSet == 0);
//
//    ordered_array_set_delete(set1);
//}
//
//void test_ordered_array_set_in() {
//    test_ordered_array_set_in1();
//    test_ordered_array_set_in2();
//    printf("in\n");
//}
//
//void test_ordered_array_set_isSubset1() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    bool resSet = ordered_array_set_isSubset(set1, set2);
//    assert (resSet == 0);
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//}
//
//void test_ordered_array_set_isSubset2() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {2}, 1);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    bool resSet = ordered_array_set_isSubset(set1, set2);
//    assert (resSet == 1);
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//}
//
//void test_ordered_array_set_isSubset() {
//    test_ordered_array_set_isSubset1();
//    test_ordered_array_set_isSubset2();
//    printf("subset\n");
//}
//
//void test_ordered_array_set_insert1() {
//    ordered_array_set set1 = ordered_array_set_create(3);
//    ordered_array_set_insert(&set1, 3);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {3}, 1);
//    assert (ordered_array_set_isEqual(set1, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_insert2() {
//    ordered_array_set set1 = ordered_array_set_create(3);
//    ordered_array_set_insert(&set1, 3);
//    ordered_array_set_insert(&set1, 2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    assert (ordered_array_set_isEqual(set1, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_insert3() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    ordered_array_set_insert(&set1, 2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    assert (ordered_array_set_isEqual(set1, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_insert() {
//    test_ordered_array_set_insert1();
//    test_ordered_array_set_insert2();
//    test_ordered_array_set_insert3();
//    printf("insert\n");
//}
//
//void test_ordered_array_set_deleteElement1() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    ordered_array_set_deleteElement(&set1, 2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1}, 1);
//    assert (ordered_array_set_isEqual(set1, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_deleteElement2() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    ordered_array_set_deleteElement(&set1, 1);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2}, 1);
//    assert (ordered_array_set_isEqual(set1, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_deleteElement3() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    ordered_array_set_deleteElement(&set1, 3);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    assert (ordered_array_set_isEqual(set1, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_deleteElement() {
//    test_ordered_array_set_deleteElement1();
//    test_ordered_array_set_deleteElement2();
//    test_ordered_array_set_deleteElement3();
//    printf("del\n");
//}
//
//void test_ordered_array_set_union1() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    ordered_array_set resSet = ordered_array_set_union(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_union2() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {}, 0);
//    ordered_array_set resSet = ordered_array_set_union(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_union() {
//    test_ordered_array_set_union1();
//    test_ordered_array_set_union2();
//    printf("uni\n");
//}
//
//
//void test_ordered_array_set_intersection1() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2}, 1);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_intersection2() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {}, 0);
//    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {}, 0);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_intersection() {
//    test_ordered_array_set_intersection1();
//    test_ordered_array_set_intersection2();
//    printf("inter\n");
//}
//
//void test_ordered_array_set_difference1() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 4, 5}, 4);
//    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {3}, 1);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_difference2() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {}, 0);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_difference() {
//    test_ordered_array_set_difference1();
//    test_ordered_array_set_difference2();
//    printf("diff\n");
//}
//
//void test_ordered_array_set_symmetricDifference1() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 4, 5}, 4);
//    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {3, 4, 5}, 3);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_symmetricDifference2() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
//    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {4}, 1);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_symmetricDifference() {
//    test_ordered_array_set_symmetricDifference1();
//    test_ordered_array_set_symmetricDifference2();
//    printf("sumdiff\n");
//}
//
//void test_ordered_array_set_complement1() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
//    ordered_array_set resSet = ordered_array_set_complement(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {4}, 1);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_complement2() {
//    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
//    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
//    ordered_array_set resSet = ordered_array_set_complement(set1, set2);
//    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 4}, 2);
//    assert (ordered_array_set_isEqual(resSet, expectedSet));
//
//    ordered_array_set_delete(set1);
//    ordered_array_set_delete(set2);
//    ordered_array_set_delete(resSet);
//    ordered_array_set_delete(expectedSet);
//}
//
//void test_ordered_array_set_complement() {
//    test_ordered_array_set_complement1();
//    test_ordered_array_set_complement2();
//    printf("comp\n");
//}
//
//
//void test1() {
//    test_unordered_array_set_in();
//    test_unordered_array_set_isSubset();
//    test_unordered_array_set_insert();
//    test_unordered_array_set_deleteElement();
//    test_unordered_array_union();
//    test_unordered_array_intersection();
//    test_unordered_array_set_difference();
//    test_unordered_array_set_symmetricDifference();
//    test_unordered_array_set_complement();
//    printf("ok");
//}
//
//void test2() {
//    test_ordered_array_set_in();
//    test_ordered_array_set_isSubset();
//    test_ordered_array_set_insert();
//    test_ordered_array_set_deleteElement();
//    test_ordered_array_set_union();
//    test_ordered_array_set_intersection();
//    test_ordered_array_set_difference();
//    test_ordered_array_set_symmetricDifference();
//    test_ordered_array_set_complement();
//    printf("success");
//}
//
//void test_swapRows1() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 1, 0,
//                    0, 0, 0,
//                    0, 0, 1,
//                    0, 0, 0,
//                    0, 1, 1,
//            },
//            5, 3
//    );
//    swapRows(m, 1, 2);
//    matrix expectedMatrix = createMatrixFromArray(
//            (int[]) {
//                    1, 1, 0,
//                    0, 0, 1,
//                    0, 0, 0,
//                    0, 0, 0,
//                    0, 1, 1,
//            },
//            5, 3
//    );
//    assert(areTwoMatricesEqual(&m, &expectedMatrix) == 1);
//    freeMemMatrix(m);
//    freeMemMatrix(expectedMatrix);
//}
//
//void test_swapRows2() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 1, 0,
//                    0, 0, 0,
//                    0, 0, 1,
//                    0, 0, 0,
//                    0, 1, 1,
//            },
//            5, 3
//    );
//    swapRows(m, 0, 4);
//    matrix expectedMatrix = createMatrixFromArray(
//            (int[]) {
//                    0, 1, 1,
//                    0, 0, 0,
//                    0, 0, 1,
//                    0, 0, 0,
//                    1, 1, 0,
//            },
//            5, 3
//    );
//    assert(areTwoMatricesEqual(&m, &expectedMatrix) == 1);
//    freeMemMatrix(m);
//    freeMemMatrix(expectedMatrix);
//}
//
//void test_swapRows() {
//    test_swapRows1();
//    test_swapRows2();
//}
//
//void test_swapCols1() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 1, 0,
//                    0, 0, 0,
//                    0, 0, 1,
//                    0, 0, 0,
//                    0, 1, 1,
//            },
//            5, 3
//    );
//    swapColumns(m, 0, 2);
//    matrix expectedMatrix = createMatrixFromArray(
//            (int[]) {
//                    0, 1, 1,
//                    0, 0, 0,
//                    1, 0, 0,
//                    0, 0, 0,
//                    1, 1, 0,
//            },
//            5, 3
//    );
//    assert(areTwoMatricesEqual(&m, &expectedMatrix) == 1);
//    freeMemMatrix(m);
//    freeMemMatrix(expectedMatrix);
//}
//
//void test_swapCols2() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 1, 0,
//                    0, 0, 0,
//                    0, 0, 1,
//                    0, 0, 0,
//                    1, 0, 1,
//            },
//            5, 3
//    );
//    swapColumns(m, 0, 1);
//    matrix expectedMatrix = createMatrixFromArray(
//            (int[]) {
//                    1, 1, 0,
//                    0, 0, 0,
//                    0, 0, 1,
//                    0, 0, 0,
//                    0, 1, 1,
//            },
//            5, 3
//    );
//    assert(areTwoMatricesEqual(&m, &expectedMatrix) == 1);
//    freeMemMatrix(m);
//    freeMemMatrix(expectedMatrix);
//}
//
//void test_swapCols() {
//    test_swapCols1();
//    test_swapCols2();
//}
//
//
//int getMin(int const *a, int n) {
//    assert(n > 0);
//
//    int min = a[0];
//    for (int i = 1; i < n; i++)
//        if (a[i] < min)
//            min = a[i];
//
//    return min;
//}
//
//
//void test_SortRows1() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    4, 5, 6,
//                    1, 2, 3,
//                    7, 8, 9,
//            },
//            3, 3
//    );
//    insertionSortRowsMatrixByRowCriteria(m, getMin);
//    matrix expectedMatrix = createMatrixFromArray(
//            (int[]) {
//                    1, 2, 3,
//                    4, 5, 6,
//                    7, 8, 9,
//
//            },
//            3, 3
//    );
//    assert(areTwoMatricesEqual(&m, &expectedMatrix) == 1);
//    freeMemMatrix(m);
//    freeMemMatrix(expectedMatrix);
//}
//
//void test_SortCols1() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    4, 6, 9,
//                    1, 3, 2,
//                    7, 8, 8,
//            },
//            3, 3
//    );
//    selectionSortColsMatrixByColCriteria(m, getMin);
//    matrix expectedMatrix = createMatrixFromArray(
//            (int[]) {
//                    4, 9, 6,
//                    1, 2, 3,
//                    7, 8, 8,
//            },
//            3, 3
//    );
//    assert(areTwoMatricesEqual(&m, &expectedMatrix) == 1);
//    freeMemMatrix(m);
//    freeMemMatrix(expectedMatrix);
//}
//
//void test_isSquare1() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 1, 0,
//                    0, 0, 0,
//                    0, 0, 1,
//                    0, 0, 0,
//                    0, 1, 1,
//            },
//            5, 3
//    );
//    assert(isSquareMatrix(m) == 0);
//    freeMemMatrix(m);
//}
//
//void test_isSquare2() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 1, 0,
//                    0, 0, 0,
//                    0, 0, 1,
//            },
//            3, 3
//    );
//    assert(isSquareMatrix(m) == 1);
//    freeMemMatrix(m);
//}
//
//void test_isSquare() {
//    test_isSquare1();
//    test_isSquare2();
//}
//
//void test_eMatrix1() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 0, 0,
//                    0, 1, 0,
//                    0, 0, 1,
//            },
//            3, 3
//    );
//    assert(isEMatrix(&m) == 1);
//    freeMemMatrix(m);
//}
//
//void test_eMatrix2() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 0, 0,
//                    0, 1, 0,
//                    1, 0, 1,
//            },
//            3, 3
//    );
//    assert(isEMatrix(&m) == 0);
//    freeMemMatrix(m);
//}
//
//void test_eMatrix() {
//    test_eMatrix1();
//    test_eMatrix2();
//}
//
//void test_symmetricMatrix1() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 0, 0,
//                    0, 1, 0,
//                    0, 0, 1,
//            },
//            3, 3
//    );
//    assert(isSymmetricMatrix(&m) == 1);
//    freeMemMatrix(m);
//}
//
//void test_symmetricMatrix2() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 0, 0,
//                    0, 1, 0,
//                    1, 0, 1,
//            },
//            3, 3
//    );
//    assert(isSymmetricMatrix(&m) == 0);
//    freeMemMatrix(m);
//}
//
//void test_symmetricMatrix() {
//    test_symmetricMatrix1();
//    test_symmetricMatrix2();
//}
//
//
//void test_transposeS() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    4, 9, 6,
//                    1, 2, 3,
//                    7, 8, 8,
//            },
//            3, 3
//    );
//    transposeSquareMatrix(&m);
//    matrix expectedMatrix = createMatrixFromArray(
//            (int[]) {
//                    4, 1, 7,
//                    9, 2, 8,
//                    6, 3, 8,
//
//            },
//            3, 3
//    );
//    assert(areTwoMatricesEqual(&m, &expectedMatrix) == 1);
//    freeMemMatrix(m);
//    freeMemMatrix(expectedMatrix);
//}
//
//void test_transposeM() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    4, 9, 6,
//                    1, 2, 3,
//                    7, 8, 8,
//                    1, 1, 1
//            },
//            4, 3
//    );
//    transposeMatrix(&m);
//    matrix expectedMatrix = createMatrixFromArray(
//            (int[]) {
//                    4, 1, 7, 1,
//                    9, 2, 8, 1,
//                    6, 3, 8, 1,
//
//            },
//            3, 4
//    );
//    assert(areTwoMatricesEqual(&m, &expectedMatrix) == 1);
//    freeMemMatrix(m);
//    freeMemMatrix(expectedMatrix);
//}
//
//void test_MinValuePos() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 0, 0,
//                    0, 1, 0,
//                    1, 0, 1,
//            },
//            3, 3
//    );
//    position res = getMinValuePos(m);
//    position expectedPos = {0, 1};
//    assert((res.colIndex == expectedPos.colIndex) && (res.rowIndex == expectedPos.rowIndex));
//    freeMemMatrix(m);
//}
//
//void test_MaxValuePos() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 0, 0,
//                    0, 1, 0,
//                    1, 0, 1,
//            },
//            3, 3
//    );
//    assert(isSymmetricMatrix(&m) == 0);
//    freeMemMatrix(m);
//}
//
//void test3() {
//    test_swapRows();
//    test_swapCols();
//    test_SortRows1();
//    test_SortCols1();
//    test_isSquare();
//    test_eMatrix();
//    test_symmetricMatrix();
//    test_transposeS();
//    test_transposeM();
//    test_MinValuePos();
//    printf("sucsess matrix");
//}

void test_pushBack_emptyVector() {
    vector a = createVector(10);
    pushBack(&a, 6);
    if (a.data[0] == 6)
        printf("pushBack_emptyVector_ok\n");
}

void test_pushBackfullVector() {
    vector a = createVector(1);
    a.data[0] = 1;
    a.size = 1;
    pushBack(&a, 6);
    if (a.data[1] == 6)
        printf("pushBack_fullVector_ok\n");
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    printf("popBack_notEmptyVector_ok\n");
}


void test(){
    test_pushBack_emptyVector();
    test_pushBackfullVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();

    return 0;
}
