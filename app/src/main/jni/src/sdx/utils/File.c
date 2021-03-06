/** updated by adriac */
/* File.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from File.vala, do not modify */

/*[Adriac:Sdx.Utils::File:SdxUtilsFile:sdx_utils_file]*/
/* ******************************************************************************
 * Copyright 2017 darkoverlordofdata.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <SDL_rwops.h>

typedef struct _SdxUtilsFile SdxUtilsFile;
#define _SDL_FreeRW0(var) ((var == NULL) ? NULL : (var = (SDL_FreeRW (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _SdxUtilsFile {
	gint ref_count;
	SDL_RWops* file;
	gchar* path;
	gchar** files;
	gint files_length1;
};



#define SDX_UTILS_PathSeparator "/"
#define SDX_UTILS_PathSeparatorChar '/'
void sdx_utils_file_free (SdxUtilsFile * self);
static void sdx_utils_file_instance_init (SdxUtilsFile * self);
SdxUtilsFile* sdx_utils_file_retain (SdxUtilsFile* self);
void sdx_utils_file_release (SdxUtilsFile* self);
void sdx_utils_file_free (SdxUtilsFile* self);
SdxUtilsFile* sdx_utils_file_new (const gchar* path);
gchar* sdx_utils_file_GetPath (SdxUtilsFile* self);
gchar* sdx_utils_file_GetName (SdxUtilsFile* self);
gchar* sdx_utils_file_GetParent (SdxUtilsFile* self);
gboolean sdx_utils_file_Exists (SdxUtilsFile* self);
gboolean sdx_utils_file_IsFile (SdxUtilsFile* self);
gboolean sdx_utils_file_IsDirectory (SdxUtilsFile* self);
gint sdx_utils_file_Length (SdxUtilsFile* self);
gchar* sdx_utils_file_Read (SdxUtilsFile* self);
gchar** sdx_utils_file_List (SdxUtilsFile* self, int* result_length1);
static gchar** _vala_array_dup6 (gchar** self, int length);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


SdxUtilsFile* sdx_utils_file_retain (SdxUtilsFile* self) {
	SdxUtilsFile* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->ref_count), 1);
	result = self;
	return result;
}


void sdx_utils_file_release (SdxUtilsFile* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->ref_count));
	if (_tmp0_) {
		sdx_utils_file_free (self);
	}
}


SdxUtilsFile* sdx_utils_file_new (const gchar* path) {
	SdxUtilsFile* self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	SDL_RWops* _tmp3_;
	g_return_val_if_fail (path != NULL, NULL);
	self = g_slice_new0 (SdxUtilsFile);
	sdx_utils_file_instance_init (self);
	_tmp0_ = path;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->path);
	self->path = _tmp1_;
	_tmp2_ = path;
	_tmp3_ = SDL_RWFromFile (_tmp2_, "r");
	_SDL_FreeRW0 (self->file);
	self->file = _tmp3_;
	return self;
}


gchar* sdx_utils_file_GetPath (SdxUtilsFile* self) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->path;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}


/**
 * the name is everything after the final separator
 */
static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_;
	gchar _tmp1_;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


static glong string_strnlen (gchar* str, glong maxlen) {
	glong result = 0L;
	gchar* end = NULL;
	gchar* _tmp0_;
	glong _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	_tmp0_ = str;
	_tmp1_ = maxlen;
	_tmp2_ = memchr (_tmp0_, 0, (gsize) _tmp1_);
	end = _tmp2_;
	_tmp3_ = end;
	if (_tmp3_ == NULL) {
		glong _tmp4_;
		_tmp4_ = maxlen;
		result = _tmp4_;
		return result;
	} else {
		gchar* _tmp5_;
		gchar* _tmp6_;
		_tmp5_ = end;
		_tmp6_ = str;
		result = (glong) (_tmp5_ - _tmp6_);
		return result;
	}
}


static gchar* string_SubString (const gchar* self, glong offset, glong len) {
	gchar* result = NULL;
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	glong _tmp1_;
	glong _tmp8_;
	glong _tmp14_;
	glong _tmp17_;
	glong _tmp18_;
	glong _tmp19_;
	glong _tmp20_;
	glong _tmp21_;
	gchar* _tmp22_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = offset;
	if (_tmp1_ >= ((glong) 0)) {
		glong _tmp2_;
		_tmp2_ = len;
		_tmp0_ = _tmp2_ >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		glong _tmp3_;
		glong _tmp4_;
		glong _tmp5_;
		_tmp3_ = offset;
		_tmp4_ = len;
		_tmp5_ = string_strnlen ((gchar*) self, _tmp3_ + _tmp4_);
		string_length = _tmp5_;
	} else {
		gint _tmp6_;
		gint _tmp7_;
		_tmp6_ = strlen (self);
		_tmp7_ = _tmp6_;
		string_length = (glong) _tmp7_;
	}
	_tmp8_ = offset;
	if (_tmp8_ < ((glong) 0)) {
		glong _tmp9_;
		glong _tmp10_;
		glong _tmp11_;
		_tmp9_ = string_length;
		_tmp10_ = offset;
		offset = _tmp9_ + _tmp10_;
		_tmp11_ = offset;
		g_return_val_if_fail (_tmp11_ >= ((glong) 0), NULL);
	} else {
		glong _tmp12_;
		glong _tmp13_;
		_tmp12_ = offset;
		_tmp13_ = string_length;
		g_return_val_if_fail (_tmp12_ <= _tmp13_, NULL);
	}
	_tmp14_ = len;
	if (_tmp14_ < ((glong) 0)) {
		glong _tmp15_;
		glong _tmp16_;
		_tmp15_ = string_length;
		_tmp16_ = offset;
		len = _tmp15_ - _tmp16_;
	}
	_tmp17_ = offset;
	_tmp18_ = len;
	_tmp19_ = string_length;
	g_return_val_if_fail ((_tmp17_ + _tmp18_) <= _tmp19_, NULL);
	_tmp20_ = offset;
	_tmp21_ = len;
	_tmp22_ = g_strndup (((gchar*) self) + _tmp20_, (gsize) _tmp21_);
	result = _tmp22_;
	return result;
}


gchar* sdx_utils_file_GetName (SdxUtilsFile* self) {
	gchar* result = NULL;
	const gchar* _tmp12_;
	gchar* _tmp13_;
	g_return_val_if_fail (self != NULL, NULL);
	{
		gint i = 0;
		const gchar* _tmp0_;
		gint _tmp1_;
		gint _tmp2_;
		_tmp0_ = self->path;
		_tmp1_ = strlen (_tmp0_);
		_tmp2_ = _tmp1_;
		i = _tmp2_ - 1;
		{
			gboolean _tmp3_ = FALSE;
			_tmp3_ = TRUE;
			while (TRUE) {
				gint _tmp5_;
				const gchar* _tmp6_;
				gint _tmp7_;
				gchar _tmp8_;
				if (!_tmp3_) {
					gint _tmp4_;
					_tmp4_ = i;
					i = _tmp4_ - 1;
				}
				_tmp3_ = FALSE;
				_tmp5_ = i;
				if (!(_tmp5_ > 0)) {
					break;
				}
				_tmp6_ = self->path;
				_tmp7_ = i;
				_tmp8_ = string_get (_tmp6_, (glong) _tmp7_);
				if (_tmp8_ == SDX_UTILS_PathSeparatorChar) {
					const gchar* _tmp9_;
					gint _tmp10_;
					gchar* _tmp11_;
					_tmp9_ = self->path;
					_tmp10_ = i;
					_tmp11_ = string_SubString (_tmp9_, (glong) (_tmp10_ + 1), (glong) -1);
					result = _tmp11_;
					return result;
				}
			}
		}
	}
	_tmp12_ = self->path;
	_tmp13_ = g_strdup (_tmp12_);
	result = _tmp13_;
	return result;
}


/**
 * the parent is everything prior to the final separator
 */
static gint string_LastIndexOf (const gchar* self, const gchar* needle, gint start_index) {
	gint result = 0;
	gchar* _result_ = NULL;
	gint _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (needle != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = needle;
	_tmp2_ = g_strrstr (((gchar*) self) + _tmp0_, (gchar*) _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


gchar* sdx_utils_file_GetParent (SdxUtilsFile* self) {
	gchar* result = NULL;
	gint i = 0;
	const gchar* _tmp0_;
	gint _tmp1_;
	gchar* _tmp2_ = NULL;
	gint _tmp3_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->path;
	_tmp1_ = string_LastIndexOf (_tmp0_, SDX_UTILS_PathSeparator, 0);
	i = _tmp1_;
	_tmp3_ = i;
	if (_tmp3_ < 0) {
		gchar* _tmp4_;
		_tmp4_ = g_strdup ("");
		_g_free0 (_tmp2_);
		_tmp2_ = _tmp4_;
	} else {
		const gchar* _tmp5_;
		gint _tmp6_;
		gchar* _tmp7_;
		_tmp5_ = self->path;
		_tmp6_ = i;
		_tmp7_ = string_SubString (_tmp5_, (glong) 0, (glong) _tmp6_);
		_g_free0 (_tmp2_);
		_tmp2_ = _tmp7_;
	}
	result = _tmp2_;
	return result;
}


/**
 * check if the represented struture exists on the virtual disk
 */
gboolean sdx_utils_file_Exists (SdxUtilsFile* self) {
	gboolean result = FALSE;
	SDL_RWops* _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->file;
	result = _tmp0_ != NULL;
	return result;
}


/**
 * is it a file?
 */
gboolean sdx_utils_file_IsFile (SdxUtilsFile* self) {
	gboolean result = FALSE;
	SDL_RWops* _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->file;
	result = _tmp0_ != NULL;
	return result;
}


/**
 * is it a folder?
 */
gboolean sdx_utils_file_IsDirectory (SdxUtilsFile* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = FALSE;
	return result;
}


/**
 * get the length of the file
 */
gint sdx_utils_file_Length (SdxUtilsFile* self) {
	gint result = 0;
	gint _tmp0_ = 0;
	SDL_RWops* _tmp1_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp1_ = self->file;
	if (_tmp1_ != NULL) {
		SDL_RWops* _tmp2_;
		gint64 _tmp3_;
		gint64 _tmp4_;
		_tmp2_ = self->file;
		_tmp3_ = SDL_RWsize (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp0_ = (gint) _tmp4_;
	} else {
		_tmp0_ = 0;
	}
	result = _tmp0_;
	return result;
}


/**
 * read the contents into a string buffer
 */
gchar* sdx_utils_file_Read (SdxUtilsFile* self) {
	gchar* result = NULL;
	gboolean _tmp0_;
	gint size = 0;
	SDL_RWops* _tmp2_;
	gint64 _tmp3_;
	gint64 _tmp4_;
	gchar* ioBuff = NULL;
	gint _tmp5_;
	gchar* _tmp6_;
	gint ioBuff_length1;
	gint _ioBuff_size_;
	gsize stat = 0UL;
	SDL_RWops* _tmp7_;
	gchar* _tmp8_;
	gint _tmp8__length1;
	gint _tmp9_;
	gsize _tmp10_;
	gchar* lines = NULL;
	gchar* _tmp11_;
	const gchar* _tmp12_;
	gchar* _tmp13_;
	gint _tmp13__length1;
	gchar* _tmp14_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = sdx_utils_file_Exists (self);
	if (!_tmp0_) {
		gchar* _tmp1_;
		_tmp1_ = g_strdup ("");
		result = _tmp1_;
		return result;
	}
	_tmp2_ = self->file;
	_tmp3_ = SDL_RWsize (_tmp2_);
	_tmp4_ = _tmp3_;
	size = (gint) _tmp4_;
	_tmp5_ = size;
	_tmp6_ = g_new0 (gchar, _tmp5_ + 2);
	ioBuff = _tmp6_;
	ioBuff_length1 = _tmp5_ + 2;
	_ioBuff_size_ = ioBuff_length1;
	_tmp7_ = self->file;
	_tmp8_ = ioBuff;
	_tmp8__length1 = ioBuff_length1;
	_tmp9_ = size;
	_tmp10_ = SDL_RWread (_tmp7_, (void*) _tmp8_, (gsize) 2, ((gsize) _tmp9_) / 2);
	stat = _tmp10_;
	_tmp11_ = g_strdup ("");
	lines = _tmp11_;
	_tmp12_ = lines;
	_tmp13_ = ioBuff;
	_tmp13__length1 = ioBuff_length1;
	_tmp14_ = g_strconcat (_tmp12_, (const gchar*) _tmp13_, NULL);
	_g_free0 (lines);
	lines = _tmp14_;
	result = lines;
	ioBuff = (g_free (ioBuff), NULL);
	return result;
}


/**
 * return the list of files in the folder
 */
static gchar** _vala_array_dup6 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


gchar** sdx_utils_file_List (SdxUtilsFile* self, int* result_length1) {
	gchar** result = NULL;
	gchar** _tmp0_;
	gchar** _tmp1_;
	gint _tmp1__length1;
	gchar** _tmp2_;
	gint _tmp2__length1;
	gchar** _tmp3_;
	gint _tmp3__length1;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_new0 (gchar*, 0 + 1);
	self->files = (_vala_array_free (self->files, self->files_length1, (GDestroyNotify) g_free), NULL);
	self->files = _tmp0_;
	self->files_length1 = 0;
	_tmp1_ = self->files;
	_tmp1__length1 = self->files_length1;
	_tmp2_ = (_tmp1_ != NULL) ? _vala_array_dup6 (_tmp1_, _tmp1__length1) : ((gpointer) _tmp1_);
	_tmp2__length1 = _tmp1__length1;
	_tmp3_ = _tmp2_;
	_tmp3__length1 = _tmp2__length1;
	if (result_length1) {
		*result_length1 = _tmp3__length1;
	}
	result = _tmp3_;
	return result;
}


static void sdx_utils_file_instance_init (SdxUtilsFile * self) {
	self->ref_count = 1;
}


void sdx_utils_file_free (SdxUtilsFile * self) {
	_SDL_FreeRW0 (self->file);
	_g_free0 (self->path);
	self->files = (_vala_array_free (self->files, self->files_length1, (GDestroyNotify) g_free), NULL);
	g_slice_free (SdxUtilsFile, self);
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}




