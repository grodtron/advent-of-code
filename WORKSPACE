load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "ranges",
    remote = "https://github.com/ericniebler/range-v3.git",
    tag = "0.12.0"
)

git_repository(
    name = "gtest",
    remote = "https://github.com/google/googletest.git",
    tag = "release-1.12.1"
)

git_repository(
    name = "fmt",
    remote = "https://github.com/fmtlib/fmt.git",
    tag = "9.1.0",
    patch_cmds = [
        "mv support/bazel/.bazelrc .bazelrc",
        "mv support/bazel/.bazelversion .bazelversion",
        "mv support/bazel/BUILD.bazel BUILD.bazel",
        "mv support/bazel/WORKSPACE.bazel WORKSPACE.bazel",
    ]
)
