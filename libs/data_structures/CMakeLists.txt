add_library(data_structures
        unordered_array_set/unordered_array_set.c
        ordered_array_set/ordered_array_set.c
        bitset/bitset.c
        matrix/matrix.c
        vector/vector.c
        )

target_link_libraries(data_structures algorithms)
