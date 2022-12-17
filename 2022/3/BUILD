cc_library(
    name = "solution",
    srcs = ["solution.cc"],
    hdrs = ["solution.hh"],
    copts = ["-std=c++20"],
    deps = [
        "@ranges//:range-v3",
        "@fmt//:fmt",
    ]
)

cc_binary(
    name = "puzzle",
    deps = [
        "//advent/of/code:main",
        ":solution"
    ]
)
