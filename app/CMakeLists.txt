add_executable(hydrosheds_app hydrosheds_app.cc)
target_link_libraries(hydrosheds_app PRIVATE hydrosheds)

add_executable(rasterize_app rasterize_app.cc)
target_link_libraries(rasterize_app PRIVATE rasterize)