#include "vfs_wrapper.h"
#include "py/stream.h"
#include "extmod/vfs.h"
#include "py/runtime.h"

/************ File OP ************/
int file_write_open(mp_obj_t* fp, const char *path)
{
    return 0;
}

int file_write_open_raise(mp_obj_t* fp, const char *path)
{
    return 0;
}

int file_read_open(mp_obj_t* fp, const char *path)
{
    return 0;
}

int file_read_open_raise(mp_obj_t* fp, const char *path)
{
    return 0;
}


int file_close(mp_obj_t fp)
{
    return 0;
}

int file_seek(mp_obj_t fp, mp_int_t offset, uint8_t whence)
{
    return 0;
}

bool file_eof(mp_obj_t fp)
{
    return 0;
}

int file_seek_raise(mp_obj_t fp, mp_int_t offset, uint8_t whence)
{
    return 0;
}

mp_uint_t file_save_data(const char* path, uint8_t* data, mp_uint_t length, int* error_code)
{
    return 0;
}

mp_uint_t file_size(mp_obj_t fp)
{
    return 0;
}


void file_buffer_on(mp_obj_t fp)
{
	//TODO
}

void file_buffer_off(mp_obj_t fp)
{
	//TODO
}

/************ Raise ************/
NORETURN static void fs_fail(mp_obj_t fp, int res)
{
    int err=0;
    nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError, ffs_strerror(res)));
}

NORETURN static void fs_read_fail(mp_obj_t fp)
{
    int err=0;
    nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError, "Failed to read requested bytes!"));
}

NORETURN static void fs_write_fail(mp_obj_t fp)
{
    int err=0;
    nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError, "Failed to write requested bytes!"));
}

NORETURN static void fs_expect_fail(mp_obj_t fp)
{
    int err=0;
    nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError, "Unexpected value read!"));
}

NORETURN void fs_unsupported_format(mp_obj_t fp)
{
    int err=0;
    nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError, "Unsupported format!"));
}

NORETURN void fs_file_corrupted(mp_obj_t fp)
{
    int err=0;
    nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError, "File corrupted!"));
}

NORETURN void fs_not_equal(mp_obj_t fp)
{
    int err=0;
    nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError, "Images not equal!"));
}

NORETURN void fs_no_intersection(mp_obj_t fp)
{
    int err=0;
    nlr_raise(mp_obj_new_exception_msg(&mp_type_OSError, "No intersection!"));
}

int file_corrupted_raise(mp_obj_t fp)
{
	mp_raise_ValueError("file_corrupted_raise!");
	return 1;
}

const char *ffs_strerror(int res)
{
    return "ERROR CODE: TODO";
}



//before raise, must close fp.
/************ RW byte ************/
int read_byte(mp_obj_t fp, uint8_t* value)
{
    return 0;
}

int read_byte_raise(mp_obj_t fp, uint8_t* value)
{
    return 0;
}

int read_byte_expect(mp_obj_t fp, uint8_t value)
{
    return 0;
}

int read_byte_ignore(mp_obj_t fp)
{
    return 0;
}

int write_byte(mp_obj_t fp, uint8_t value)
{
    return 0;
}

int write_byte_raise(mp_obj_t fp, uint8_t value)
{
    return 0;
}

/************ RW word ************/
int read_word(mp_obj_t fp, uint16_t* value)
{
    return 0;
}

int read_word_raise(mp_obj_t fp, uint16_t* value)
{
    return 0;
}

int read_word_expect(mp_obj_t fp, uint16_t value)
{
    return 0;
}

int read_word_ignore(mp_obj_t fp)
{
    return 0;
}

int write_word(mp_obj_t fp, uint16_t value)
{
    return 0;
}

int write_word_raise(mp_obj_t fp, uint16_t value)
{
    return 0;
}

/************ RW long ************/
int read_long(mp_obj_t fp, uint32_t* value)
{
    return 0;
}

int read_long_raise(mp_obj_t fp, uint32_t* value)
{
    return 0;
}

int read_long_expect(mp_obj_t fp, uint32_t value)
{
    return 0;
}

int read_long_ignore(mp_obj_t fp)
{
    return 0;
}

int write_long(mp_obj_t fp, uint32_t value)
{
    return 0;
}

int write_long_raise(mp_obj_t fp, uint32_t value)
{
    return 0;
}

/************ RW Data ************/
int read_data(mp_obj_t fp, void *data, mp_uint_t size)
{
    return 0;
}

int file_read(mp_obj_t fp, void *data, mp_uint_t size, mp_uint_t* size_out)
{
    return 0;
}

int read_data_raise(mp_obj_t fp, void *data, mp_uint_t size)
{
    return 0;
}

int write_data(mp_obj_t fp, const void *data, mp_uint_t size)
{
    return 0;
}  

int file_write(mp_obj_t fp, void *data, mp_uint_t size, mp_uint_t* size_out)
{
    return 0;
}

int write_data_raise(mp_obj_t fp, const void *data, mp_uint_t size)
{
    return 0;
} 




