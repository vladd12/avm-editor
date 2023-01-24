include(FetchContent)
# Getting SQLiteCpp sources from GitHub repository
FetchContent_Declare(
    sqlitecpp
    GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp.git
    GIT_TAG        bd5bf7996adaafad736ec5b4a185e9822edbe95c # v3.2.1
)
# Compiling SQLiteCpp library
FetchContent_MakeAvailable(sqlitecpp)

# Building error: https://github.com/SRombauts/SQLiteCpp/issues/326
# Solution: git config --global core.autocrlf input
