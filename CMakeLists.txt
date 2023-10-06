cmake_minimum_required(VERSION 3.2)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( lanchonete
                src/main.cpp
                src/gerente.cpp
                src/cliente.cpp )
