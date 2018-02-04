cmake_minimum_required(VERSION 3.5)
project(algo)

aux_source_directory(. DES_SRC)
add_executable(algo ${DES_SRC} acm/threadpool.cc acm/threadpool.h DeepLearn/LSTM.cc acm/List.cc acm/str.cc acm/str.h struct/Base_List.cc struct/Base_List.h struct/base/Base_Iterator.h struct/base/Base_List_Test.cc struct/base/Base_Sort.cc struct/base/Base_Sort.h)

