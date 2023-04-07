#include "bitset.h"

bitset bitset_create(unsigned setMaxValue) {
    assert (setMaxValue < 32);
    return (bitset) {0, setMaxValue};
}


bool bitset_in(bitset set, unsigned value) {
    return (set.values >> value & 1) == 1 ? true : false;
}


bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values ? true : false;
}


bool bitset_isSubset(bitset subset, bitset set) {
    return (set.values & subset.values) == subset.values;
}


void bitset_insert(bitset *set, unsigned value) {
    set->values = set->values | (1 << value);
}


void bitset_deleteElement(bitset *set, unsigned value) {
    set->values = set->values & ~(1 << value);
}


bitset bitset_union(bitset set1, bitset set2) {
    return (bitset) {
            set1.values | set2.values,
            set1.maxValue > set2.maxValue ? set1.maxValue : set2.maxValue
    };
}


bitset bitset_intersection(bitset set1, bitset set2) {
    return (bitset) {
            set1.values & set2.values,
            set1.maxValue > set2.maxValue ? set1.maxValue : set2.maxValue
    };
}


bitset bitset_difference(bitset set1, bitset set2) {
    return (bitset) {
            set1.values & ~set2.values,
            set1.maxValue > set2.maxValue ? set1.maxValue : set2.maxValue
    };
}


bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    return (bitset) {
            set1.values ^ set2.values,
            set1.maxValue > set2.maxValue ? set1.maxValue : set2.maxValue
    };
}


bitset bitset_complement(bitset set) {
    return (bitset) {
            (~set.values << (32 - set.maxValue)) >> (32 - set.maxValue),
            set.maxValue
    };
}


void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

