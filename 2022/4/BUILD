cc_library(
    name = "solution",
    srcs = ["solution.cc"],
    hdrs = ["solution.hh"],
    copts = ["-std=c++2b"],
    deps = [
        "@ranges//:range-v3",
        "@fmt//:fmt",
        "//lib/ranges:to_int",
        "//lib/ranges:to_sorted_pair",
        "//lib/ranges:to_tuple",
    ]
)

cc_binary(
    name = "puzzle",
    deps = [
        "//advent/of/code:main",
        ":solution"
    ]
)
