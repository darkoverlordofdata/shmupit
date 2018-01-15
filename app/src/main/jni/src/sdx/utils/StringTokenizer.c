/** updated by adriac */
/* StringTokenizer.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from StringTokenizer.vala, do not modify */

/*[Adriac:Sdx.Utils::StringTokenizer:SdxUtilsStringTokenizer:sdx_utils_string_tokenizer]*/
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

typedef struct _SdxUtilsStringTokenizer SdxUtilsStringTokenizer;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _SdxUtilsStringTokenizer {
	gint ref_count;
	gint currentPosition;
	gint newPosition;
	gint maxPosition;
	gchar* str;
	gchar* delimiters;
	gboolean retDelims;
	gboolean delimsChanged;
	gint maxDelimCodePoint;
	gint* delimiterCodePoints;
	gint delimiterCodePoints_length1;
};

typedef enum  {
	SDX_SDL_EXCEPTION_Initialization,
	SDX_SDL_EXCEPTION_ImageInitialization,
	SDX_SDL_EXCEPTION_TtfInitialization,
	SDX_SDL_EXCEPTION_TextureFilteringNotEnabled,
	SDX_SDL_EXCEPTION_OpenWindow,
	SDX_SDL_EXCEPTION_CreateRenderer,
	SDX_SDL_EXCEPTION_InvalidForPlatform,
	SDX_SDL_EXCEPTION_UnableToLoadResource,
	SDX_SDL_EXCEPTION_UnableToLoadSurface,
	SDX_SDL_EXCEPTION_UnableToLoadTexture,
	SDX_SDL_EXCEPTION_NullPointer,
	SDX_SDL_EXCEPTION_NoSuchElement,
	SDX_SDL_EXCEPTION_IllegalStateException,
	SDX_SDL_EXCEPTION_IllegalArgumentException,
	SDX_SDL_EXCEPTION_RuntimeException,
	SDX_SDL_EXCEPTION_NotReached
} SdxSdlException;
#define SDX_SDL_EXCEPTION sdx_sdl_exception_quark ()


void sdx_utils_string_tokenizer_free (SdxUtilsStringTokenizer * self);
static void sdx_utils_string_tokenizer_instance_init (SdxUtilsStringTokenizer * self);
SdxUtilsStringTokenizer* sdx_utils_string_tokenizer_retain (SdxUtilsStringTokenizer* self);
void sdx_utils_string_tokenizer_release (SdxUtilsStringTokenizer* self);
void sdx_utils_string_tokenizer_free (SdxUtilsStringTokenizer* self);
SdxUtilsStringTokenizer* sdx_utils_string_tokenizer_new (const gchar* str, const gchar* delim, gboolean returnDelims);
void sdx_utils_string_tokenizer_SetMaxDelimCodePoint (SdxUtilsStringTokenizer* self);
gint sdx_utils_string_tokenizer_SkipDelimiters (SdxUtilsStringTokenizer* self, gint startPos);
GQuark sdx_sdl_exception_quark (void);
gboolean sdx_utils_string_tokenizer_IsDelimiter (SdxUtilsStringTokenizer* self, gchar c);
gint sdx_utils_string_tokenizer_ScanToken (SdxUtilsStringTokenizer* self, gint startPos);
gboolean sdx_utils_string_tokenizer_HasMoreTokens (SdxUtilsStringTokenizer* self);
gchar* sdx_utils_string_tokenizer_NextToken (SdxUtilsStringTokenizer* self, const gchar* delim);
gint sdx_utils_string_tokenizer_CountTokens (SdxUtilsStringTokenizer* self);


SdxUtilsStringTokenizer* sdx_utils_string_tokenizer_retain (SdxUtilsStringTokenizer* self) {
	SdxUtilsStringTokenizer* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->ref_count), 1);
	result = self;
	return result;
}


void sdx_utils_string_tokenizer_release (SdxUtilsStringTokenizer* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->ref_count));
	if (_tmp0_) {
		sdx_utils_string_tokenizer_free (self);
	}
}


SdxUtilsStringTokenizer* sdx_utils_string_tokenizer_new (const gchar* str, const gchar* delim, gboolean returnDelims) {
	SdxUtilsStringTokenizer* self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	const gchar* _tmp5_;
	gchar* _tmp6_;
	gboolean _tmp7_;
	g_return_val_if_fail (str != NULL, NULL);
	g_return_val_if_fail (delim != NULL, NULL);
	self = g_slice_new0 (SdxUtilsStringTokenizer);
	sdx_utils_string_tokenizer_instance_init (self);
	self->currentPosition = 0;
	self->newPosition = -1;
	self->delimsChanged = FALSE;
	_tmp0_ = str;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->str);
	self->str = _tmp1_;
	_tmp2_ = str;
	_tmp3_ = strlen (_tmp2_);
	_tmp4_ = _tmp3_;
	self->maxPosition = _tmp4_;
	_tmp5_ = delim;
	_tmp6_ = g_strdup (_tmp5_);
	_g_free0 (self->delimiters);
	self->delimiters = _tmp6_;
	_tmp7_ = returnDelims;
	self->retDelims = _tmp7_;
	sdx_utils_string_tokenizer_SetMaxDelimCodePoint (self);
	return self;
}


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


void sdx_utils_string_tokenizer_SetMaxDelimCodePoint (SdxUtilsStringTokenizer* self) {
	const gchar* _tmp0_;
	gint m = 0;
	gint c = 0;
	gint count = 0;
	gint _tmp14_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->delimiters;
	if (_tmp0_ == NULL) {
		self->maxDelimCodePoint = 0;
		return;
	}
	m = 0;
	c = 0;
	count = 0;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp1_ = FALSE;
			_tmp1_ = TRUE;
			while (TRUE) {
				gint _tmp3_;
				const gchar* _tmp4_;
				gint _tmp5_;
				gint _tmp6_;
				const gchar* _tmp7_;
				gint _tmp8_;
				gchar _tmp9_;
				gint _tmp10_;
				gint _tmp11_;
				gint _tmp13_;
				if (!_tmp1_) {
					gint _tmp2_;
					_tmp2_ = i;
					i = _tmp2_ + 1;
				}
				_tmp1_ = FALSE;
				_tmp3_ = i;
				_tmp4_ = self->delimiters;
				_tmp5_ = strlen (_tmp4_);
				_tmp6_ = _tmp5_;
				if (!(_tmp3_ < (_tmp6_ - 1))) {
					break;
				}
				_tmp7_ = self->delimiters;
				_tmp8_ = i;
				_tmp9_ = string_get (_tmp7_, (glong) _tmp8_);
				c = (gint) _tmp9_;
				_tmp10_ = m;
				_tmp11_ = c;
				if (_tmp10_ < _tmp11_) {
					gint _tmp12_;
					_tmp12_ = c;
					m = _tmp12_;
				}
				_tmp13_ = count;
				count = _tmp13_ + 1;
			}
		}
	}
	_tmp14_ = m;
	self->maxDelimCodePoint = _tmp14_;
}


gint sdx_utils_string_tokenizer_SkipDelimiters (SdxUtilsStringTokenizer* self, gint startPos) {
	gint result = 0;
	const gchar* _tmp0_;
	gint position = 0;
	gint _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->delimiters;
	if (_tmp0_ == NULL) {
		GError* _tmp1_;
		gint _tmp2_ = 0;
		_tmp1_ = g_error_new_literal (SDX_SDL_EXCEPTION, SDX_SDL_EXCEPTION_NullPointer, "delimiters");
		_inner_error_ = _tmp1_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return _tmp2_;
	}
	_tmp3_ = startPos;
	position = _tmp3_;
	while (TRUE) {
		gboolean _tmp4_ = FALSE;
		gboolean _tmp5_;
		gchar c = '\0';
		const gchar* _tmp8_;
		gint _tmp9_;
		gchar _tmp10_;
		gboolean _tmp11_ = FALSE;
		gchar _tmp12_;
		gint _tmp13_;
		gint _tmp16_;
		_tmp5_ = self->retDelims;
		if (!_tmp5_) {
			gint _tmp6_;
			gint _tmp7_;
			_tmp6_ = position;
			_tmp7_ = self->maxPosition;
			_tmp4_ = _tmp6_ < _tmp7_;
		} else {
			_tmp4_ = FALSE;
		}
		if (!_tmp4_) {
			break;
		}
		_tmp8_ = self->str;
		_tmp9_ = position;
		_tmp10_ = string_get (_tmp8_, (glong) _tmp9_);
		c = _tmp10_;
		_tmp12_ = c;
		_tmp13_ = self->maxDelimCodePoint;
		if (((gint) _tmp12_) > _tmp13_) {
			_tmp11_ = TRUE;
		} else {
			gchar _tmp14_;
			gboolean _tmp15_;
			_tmp14_ = c;
			_tmp15_ = sdx_utils_string_tokenizer_IsDelimiter (self, _tmp14_);
			_tmp11_ = !_tmp15_;
		}
		if (_tmp11_) {
			break;
		}
		_tmp16_ = position;
		position = _tmp16_ + 1;
	}
	result = position;
	return result;
}


gint sdx_utils_string_tokenizer_ScanToken (SdxUtilsStringTokenizer* self, gint startPos) {
	gint result = 0;
	gint position = 0;
	gint _tmp0_;
	gboolean _tmp12_ = FALSE;
	gboolean _tmp13_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = startPos;
	position = _tmp0_;
	while (TRUE) {
		gint _tmp1_;
		gint _tmp2_;
		gchar c = '\0';
		const gchar* _tmp3_;
		gint _tmp4_;
		gchar _tmp5_;
		gboolean _tmp6_ = FALSE;
		gchar _tmp7_;
		gint _tmp8_;
		gint _tmp11_;
		_tmp1_ = position;
		_tmp2_ = self->maxPosition;
		if (!(_tmp1_ < _tmp2_)) {
			break;
		}
		_tmp3_ = self->str;
		_tmp4_ = position;
		_tmp5_ = string_get (_tmp3_, (glong) _tmp4_);
		c = _tmp5_;
		_tmp7_ = c;
		_tmp8_ = self->maxDelimCodePoint;
		if (((gint) _tmp7_) <= _tmp8_) {
			gchar _tmp9_;
			gboolean _tmp10_;
			_tmp9_ = c;
			_tmp10_ = sdx_utils_string_tokenizer_IsDelimiter (self, _tmp9_);
			_tmp6_ = _tmp10_;
		} else {
			_tmp6_ = FALSE;
		}
		if (_tmp6_) {
			break;
		}
		_tmp11_ = position;
		position = _tmp11_ + 1;
	}
	_tmp13_ = self->retDelims;
	if (_tmp13_) {
		gint _tmp14_;
		gint _tmp15_;
		_tmp14_ = startPos;
		_tmp15_ = position;
		_tmp12_ = _tmp14_ == _tmp15_;
	} else {
		_tmp12_ = FALSE;
	}
	if (_tmp12_) {
		gchar c = '\0';
		const gchar* _tmp16_;
		gint _tmp17_;
		gchar _tmp18_;
		gboolean _tmp19_ = FALSE;
		gchar _tmp20_;
		gint _tmp21_;
		_tmp16_ = self->str;
		_tmp17_ = position;
		_tmp18_ = string_get (_tmp16_, (glong) _tmp17_);
		c = _tmp18_;
		_tmp20_ = c;
		_tmp21_ = self->maxDelimCodePoint;
		if (((gint) _tmp20_) <= _tmp21_) {
			gchar _tmp22_;
			gboolean _tmp23_;
			_tmp22_ = c;
			_tmp23_ = sdx_utils_string_tokenizer_IsDelimiter (self, _tmp22_);
			_tmp19_ = _tmp23_;
		} else {
			_tmp19_ = FALSE;
		}
		if (_tmp19_) {
			gint _tmp24_;
			_tmp24_ = position;
			position = _tmp24_ + 1;
		}
	}
	result = position;
	return result;
}


gboolean sdx_utils_string_tokenizer_IsDelimiter (SdxUtilsStringTokenizer* self, gchar c) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_;
				const gchar* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				const gchar* _tmp6_;
				gint _tmp7_;
				gchar _tmp8_;
				gchar _tmp9_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->delimiters;
				_tmp4_ = strlen (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < (_tmp5_ - 1))) {
					break;
				}
				_tmp6_ = self->delimiters;
				_tmp7_ = i;
				_tmp8_ = string_get (_tmp6_, (glong) _tmp7_);
				_tmp9_ = c;
				if (_tmp8_ == _tmp9_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_utils_string_tokenizer_HasMoreTokens (SdxUtilsStringTokenizer* self) {
	gboolean result = FALSE;
	gint _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->currentPosition;
	_tmp1_ = sdx_utils_string_tokenizer_SkipDelimiters (self, _tmp0_);
	self->newPosition = _tmp1_;
	_tmp2_ = self->newPosition;
	_tmp3_ = self->maxPosition;
	result = _tmp2_ < _tmp3_;
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


gchar* sdx_utils_string_tokenizer_NextToken (SdxUtilsStringTokenizer* self, const gchar* delim) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gint _tmp3_ = 0;
	gboolean _tmp4_ = FALSE;
	gint _tmp5_;
	gint _tmp10_;
	gint _tmp11_;
	gint start = 0;
	gint _tmp13_;
	gint _tmp14_;
	gint _tmp15_;
	const gchar* _tmp16_;
	gint _tmp17_;
	gchar* _tmp18_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (delim != NULL, NULL);
	_tmp0_ = delim;
	if (g_strcmp0 (_tmp0_, "") > 0) {
		const gchar* _tmp1_;
		gchar* _tmp2_;
		_tmp1_ = delim;
		_tmp2_ = g_strdup (_tmp1_);
		_g_free0 (self->delimiters);
		self->delimiters = _tmp2_;
		self->delimsChanged = TRUE;
	}
	_tmp5_ = self->newPosition;
	if (_tmp5_ >= 0) {
		gboolean _tmp6_;
		_tmp6_ = self->delimsChanged;
		_tmp4_ = !_tmp6_;
	} else {
		_tmp4_ = FALSE;
	}
	if (_tmp4_) {
		gint _tmp7_;
		_tmp7_ = self->newPosition;
		_tmp3_ = _tmp7_;
	} else {
		gint _tmp8_;
		gint _tmp9_;
		_tmp8_ = self->currentPosition;
		_tmp9_ = sdx_utils_string_tokenizer_SkipDelimiters (self, _tmp8_);
		_tmp3_ = _tmp9_;
	}
	self->currentPosition = _tmp3_;
	self->delimsChanged = FALSE;
	self->newPosition = -1;
	_tmp10_ = self->currentPosition;
	_tmp11_ = self->maxPosition;
	if (_tmp10_ >= _tmp11_) {
		GError* _tmp12_;
		_tmp12_ = g_error_new_literal (SDX_SDL_EXCEPTION, SDX_SDL_EXCEPTION_NoSuchElement, "");
		_inner_error_ = _tmp12_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp13_ = self->currentPosition;
	start = _tmp13_;
	_tmp14_ = self->currentPosition;
	_tmp15_ = sdx_utils_string_tokenizer_ScanToken (self, _tmp14_);
	self->currentPosition = _tmp15_;
	_tmp16_ = self->str;
	_tmp17_ = self->currentPosition;
	_tmp18_ = string_SubString (_tmp16_, (glong) start, (glong) _tmp17_);
	result = _tmp18_;
	return result;
}


gint sdx_utils_string_tokenizer_CountTokens (SdxUtilsStringTokenizer* self) {
	gint result = 0;
	gint count = 0;
	gint currpos = 0;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	count = 0;
	_tmp0_ = self->currentPosition;
	currpos = _tmp0_;
	while (TRUE) {
		gint _tmp1_;
		gint _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		gint _tmp6_;
		gint _tmp7_;
		gint _tmp8_;
		gint _tmp9_;
		_tmp1_ = currpos;
		_tmp2_ = self->maxPosition;
		if (!(_tmp1_ < _tmp2_)) {
			break;
		}
		_tmp3_ = currpos;
		_tmp4_ = sdx_utils_string_tokenizer_SkipDelimiters (self, _tmp3_);
		currpos = _tmp4_;
		_tmp5_ = currpos;
		_tmp6_ = self->maxPosition;
		if (_tmp5_ >= _tmp6_) {
			break;
		}
		_tmp7_ = currpos;
		_tmp8_ = sdx_utils_string_tokenizer_ScanToken (self, _tmp7_);
		currpos = _tmp8_;
		_tmp9_ = count;
		count = _tmp9_ + 1;
	}
	result = count;
	return result;
}


static void sdx_utils_string_tokenizer_instance_init (SdxUtilsStringTokenizer * self) {
	self->ref_count = 1;
}


void sdx_utils_string_tokenizer_free (SdxUtilsStringTokenizer * self) {
	_g_free0 (self->str);
	_g_free0 (self->delimiters);
	self->delimiterCodePoints = (g_free (self->delimiterCodePoints), NULL);
	g_slice_free (SdxUtilsStringTokenizer, self);
}




