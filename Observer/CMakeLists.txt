AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(Observer ${DIR_SRCS} ../mytest/xxtea.cc ../mytest/xxtea.h ../mytest/lua_load.cc ../mytest/decrypt.cc ../mytest/rc4.cc ../mytest/rc4.h ../mytest/main.cc)