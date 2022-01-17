file(GLOB_RECURSE source_files CONFIGURE_DEPENDS "*.cpp")
target_sources(led.elf PUBLIC ${source_files})
