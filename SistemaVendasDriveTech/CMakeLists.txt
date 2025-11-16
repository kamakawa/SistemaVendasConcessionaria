cmake_minimum_required(VERSION 3.5)

project(InterfaceSistemaVendasConcessionaria VERSION 0.1 LANGUAGES CXX)

# Configurações Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Procura Qt5 ou Qt6
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Lista de fontes do projeto
set(PROJECT_SOURCES
    main.cpp

    # Backend
    backend/pessoa.h
    backend/pessoa.cpp
    backend/veiculo.h
    backend/veiculo.cpp
    backend/venda.h
    backend/venda.cpp
    backend/descontostrategy.h
    backend/descontostrategy.cpp
    backend/gerenciadordrivetech.h
    backend/gerenciadordrivetech.cpp

    # UI
    janelaprincipal.h
    janelaprincipal.cpp
    janelaprincipal.ui
    janeladelogin.h
    janeladelogin.cpp
    janeladelogin.ui
    janelaconsultarestoque.h
    janelaconsultarestoque.cpp
    janelaconsultarestoque.ui
    janelacadastrarcliente.h
    janelacadastrarcliente.cpp
    janelacadastrarcliente.ui
    janelaregistrarvenda.h
    janelaregistrarvenda.cpp
    janelaregistrarvenda.ui
    janelalistarvendas.h
    janelalistarvendas.cpp
    janelalistarvendas.ui
)

# Cria executável
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(InterfaceSistemaVendasConcessionaria
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(InterfaceSistemaVendasConcessionaria
        ${PROJECT_SOURCES}
    )
endif()

# Link com Qt Widgets
target_link_libraries(InterfaceSistemaVendasConcessionaria PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Configura bundle/Windows
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.InterfaceSistemaVendasConcessionaria)
endif()

set_target_properties(InterfaceSistemaVendasConcessionaria PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Copia a pasta 'data' automaticamente para o diretório de build do executável
add_custom_command(TARGET InterfaceSistemaVendasConcessionaria POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data
    $<TARGET_FILE_DIR:InterfaceSistemaVendasConcessionaria>/data
)

# Instalação (opcional)
include(GNUInstallDirs)
install(TARGETS InterfaceSistemaVendasConcessionaria
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(InterfaceSistemaVendasConcessionaria)
endif()
