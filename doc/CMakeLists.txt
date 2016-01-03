# only when doc build deps are installed
# % bundle install

add_custom_target(docs
    COMMAND bundle exec middleman build --clean
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc)

add_custom_target(serve_docs
    COMMAND bundle exec middleman server
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc)

add_custom_target(publish_docs
    COMMAND sh publish_doc.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc)

