cc_library(
    name = "to_tuple",
    hdrs = ["to_tuple.hh"],
    copts = ["-std=c++20"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "to_int",
    hdrs = ["to_int.hh"],
    copts = ["-std=c++20"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "to_sorted_pair",
    hdrs = ["to_sorted_pair.hh"],
    copts = ["-std=c++20"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "max_n",
    hdrs = ["max_n.hh"],
    copts = ["-std=c++20"],
    visibility = ["//visibility:public"]
)

cc_test(
    name = "test_max_n",
    srcs = ["test_max_n.cc"],
    copts = ["-std=c++20"],
    deps = [
        ":max_n",
        "@gtest//:gtest_main",
    ]
)

cc_test(
    name = "test_to_tuple",
    srcs = ["test_to_tuple.cc"],
    copts = ["-std=c++20"],
    deps = [
        ":to_tuple",
        "@gtest//:gtest_main",
    ]
)

cc_test(
    name = "test_to_int",
    srcs = ["test_to_int.cc"],
    copts = ["-std=c++20"],
    deps = [
        ":to_int",
        "@gtest//:gtest_main",
    ]
)

cc_test(
    name = "test_to_sorted_pair",
    srcs = ["test_to_sorted_pair.cc"],
    copts = ["-std=c++20"],
    deps = [
        ":to_sorted_pair",
        "@gtest//:gtest_main",
    ]
)

