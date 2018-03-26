APPLICATION := tpm_server

CC := gcc
CFLAGS := -Wfatal-errors -DGCC -D_POSIX_
LDFLAGS := -ldl -lpthread

LIBRARIES     := openssl/src/libcrypto.a
INCLUDE_DIRS  := openssl/include
LIBRARIES_DIR := Platform Simulator tpm winmock
BUILD_DIR     := build


define library_gen
$(1)_SRC     := $(shell find $(1)/src -name '*.c')
$(1)_OBJS    := $$($(1)_SRC:%.c=$(BUILD_DIR)/%.o)
$(1)_LIBNAME := $(shell echo lib$(1).a | tr '[:upper:]' '[:lower:]')
$(1)_LIB     := $(BUILD_DIR)/$(1)/$$($(1)_LIBNAME)

ALL_OBJS     += $$($(1)_OBJS)
INCLUDE_DIRS += $(1)/include $(1)/include/prototypes
LIBRARIES    += $$($(1)_LIB)

$$($(1)_LIB): $$($(1)_OBJS)
	@ar rs $$@ $$?
endef



.PHONY: compile
compile: $(BUILD_DIR)/$(APPLICATION)


# Libraries template expansion
$(foreach lib,$(LIBRARIES_DIR),$(eval $(call library_gen,$(lib))))


$(BUILD_DIR)/$(APPLICATION): $(LIBRARIES)
$(BUILD_DIR)/$(APPLICATION): LDFLAGS += -Wl,--start-group $^ -Wl,--end-group -z muldefs
$(BUILD_DIR)/$(APPLICATION):
	# Linking $@
	@$(CC) -o $@ $(LDFLAGS)


$(ALL_OBJS): $(BUILD_DIR)/%.o: %.c
	# Compiling $@
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $(addprefix -I,$(INCLUDE_DIRS)) -o $@ $<


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
