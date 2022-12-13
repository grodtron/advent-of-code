cc_binary(
    name = "puzzle",
    srcs = ["main.cc"],
    copts = ["-std=c++20"],
    deps = [
        "@ranges//:range-v3",
        "//lib/io:read_file",
        "//lib/ranges:to_tuple",
        "@fmt//:fmt",
        ":model"
    ]
)

cc_library(
    name = "model",
    srcs = ["model.cc"],
    hdrs = ["model.hh"],
    copts = ["-std=c++20"],
    deps = ["@fmt//:fmt"]
)

cc_test(
    name = "test_model",
    srcs = ["test_model.cc"],
    copts = ["-std=c++20"],
    deps = [
        ":model",
        "@gtest//:gtest_main"
    ]
)

