project(code)

set(PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/double_slider.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/worldweaver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/worldweaver.ui
)

set(PROJECT_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/worldweaver/double_slider.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/worldweaver/worldweaver.h
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/worldweaver/star.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(worldweaver
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_INCLUDES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET worldweaver APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(worldweaver SHARED
            ${PROJECT_SOURCES}
            ${PROJECT_INCLUDES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(worldweaver
            ${PROJECT_SOURCES}
            ${PROJECT_INCLUDES}
        )
    endif()
endif()

target_include_directories(worldweaver PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/inc
                           )

target_link_libraries(worldweaver PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.worldweaver)
endif()
set_target_properties(worldweaver PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS worldweaver
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(worldweaver)
endif()