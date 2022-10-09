
include_directories("../../")

function(ADD_LIB NAME SRCS DEPENDS)
    message(${NAME} " " ${SRCS})
    add_library(${NAME} SHARED "${SRCS}")
    target_link_libraries(${NAME} Lua "${DEPENDS}")
endfunction()

ADD_LIB(lib1 "lib1.c" "")
ADD_LIB(lib11 "lib11.c" "lib1")
ADD_LIB(lib2 "lib2.c" "")
ADD_LIB(lib21 "lib21.c" "lib2")
ADD_LIB(lib2-v2 "lib22.c" "")

add_custom_target(ALL_TESTES_LIBS DEPENDS LuaI lib1 lib11 lib2 lib21 lib2-v2)
