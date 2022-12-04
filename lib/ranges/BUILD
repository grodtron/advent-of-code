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
