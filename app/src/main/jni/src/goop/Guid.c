/** updated by adriac */
/* Guid.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from Guid.vala, do not modify */

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
#include "mt19937ar.h"


#define TYPE_GUID (guid_get_type ())
typedef struct _Guid Guid;
#define _g_free0(var) (var = (g_free (var), NULL))

/**
 * Guid Exceptions
 */
typedef enum  {
	GUID_EXCEPTION_StringTooShort,
	GUID_EXCEPTION_InvalidHexDigit
} GuidException;
#define GUID_EXCEPTION guid_exception_quark ()
struct _Guid {
	guint32 data1;
	guint16 data2;
	guint16 data3;
	guint8 data4[8];
};



GQuark guid_exception_quark (void);
GType guid_get_type (void) G_GNUC_CONST;
Guid* guid_dup (const Guid* self);
void guid_free (Guid* self);
gchar* guid_ToString (Guid self);
gchar* guid_Generate (void);
Guid guid_Parse (const gchar* v4);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


GQuark guid_exception_quark (void) {
	return g_quark_from_static_string ("guid_exception-quark");
}


/**
 * String representation of a Guid, 
 * formatted as "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"
 */
gchar* guid_ToString (Guid self) {
	gchar* result = NULL;
	guint32 _tmp0_;
	guint16 _tmp1_;
	guint16 _tmp2_;
	guint8 _tmp3_;
	guint8 _tmp4_;
	guint8 _tmp5_;
	guint8 _tmp6_;
	guint8 _tmp7_;
	guint8 _tmp8_;
	guint8 _tmp9_;
	guint8 _tmp10_;
	gchar* _tmp11_;
	_tmp0_ = self.data1;
	_tmp1_ = self.data2;
	_tmp2_ = self.data3;
	_tmp3_ = self.data4[0];
	_tmp4_ = self.data4[1];
	_tmp5_ = self.data4[2];
	_tmp6_ = self.data4[3];
	_tmp7_ = self.data4[4];
	_tmp8_ = self.data4[5];
	_tmp9_ = self.data4[6];
	_tmp10_ = self.data4[7];
	_tmp11_ = g_strdup_printf ("%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x", (guint) _tmp0_, (guint) _tmp1_, (guint) _tmp2_, (guint) _tmp3_, (guint) _tmp4_, (guint) _tmp5_, (guint) _tmp6_, (guint) _tmp7_, (guint) _tmp8_, (guint) _tmp9_, (guint) _tmp10_);
	result = _tmp11_;
	return result;
}


/**
 * Generate a new binary guid
 */
gchar* guid_Generate (void) {
	gchar* result = NULL;
	gulong d0 = 0UL;
	gulong _tmp0_;
	gulong d1 = 0UL;
	gulong _tmp1_;
	gulong d2 = 0UL;
	gulong _tmp2_;
	gulong d3 = 0UL;
	gulong _tmp3_;
	gulong _tmp4_;
	gulong _tmp5_;
	gulong _tmp6_;
	gulong _tmp7_;
	gulong _tmp8_;
	gulong _tmp9_;
	gulong _tmp10_;
	gulong _tmp11_;
	guint8 _tmp12_[8];
	Guid _tmp13_ = {0};
	gchar* _tmp14_;
	_tmp0_ = genrand_int32 ();
	d0 = _tmp0_;
	_tmp1_ = genrand_int32 ();
	d1 = _tmp1_;
	_tmp2_ = genrand_int32 ();
	d2 = _tmp2_;
	_tmp3_ = genrand_int32 ();
	d3 = _tmp3_;
	_tmp4_ = d1;
	d1 = (_tmp4_ & 0xffff0fffLL) | 0x00004000;
	_tmp5_ = d2;
	d2 = (_tmp5_ & 0x3fffffff) | 0x80000000LL;
	_tmp6_ = d1;
	_tmp7_ = d1;
	_tmp8_ = d2;
	_tmp9_ = d2;
	_tmp10_ = d2;
	_tmp11_ = d2;
	_tmp12_[0] = (guint8) ((_tmp8_ & 0xff000000LL) >> 24);
	_tmp12_[1] = (guint8) ((_tmp9_ & 0x00ff0000) >> 16);
	_tmp12_[2] = (guint8) ((_tmp10_ & 0x0000ff00) >> 8);
	_tmp12_[3] = (guint8) (_tmp11_ & 0x000000ff);
	_tmp12_[4] = (guint8) ((d3 & 0xff000000LL) >> 24);
	_tmp12_[5] = (guint8) ((d3 & 0x00ff0000) >> 16);
	_tmp12_[6] = (guint8) ((d3 & 0x0000ff00) >> 8);
	_tmp12_[7] = (guint8) (d3 & 0x000000ff);
	memset (&_tmp13_, 0, sizeof (Guid));
	_tmp13_.data1 = (guint32) d0;
	_tmp13_.data2 = (guint16) (_tmp6_ >> 16);
	_tmp13_.data3 = (guint16) (_tmp7_ & 0x0000ffff);
	memcpy (_tmp13_.data4, _tmp12_, 8 * sizeof (guint8));
	_tmp14_ = guid_ToString (_tmp13_);
	result = _tmp14_;
	return result;
}


/**
 * Generate a binary guid by 
 * parsing a Guid string "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"
 */
static gchar* _vala_g_strjoinv (const gchar* separator, gchar** str_array, int str_array_length1) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gchar** _tmp3_;
	gint _tmp3__length1;
	_tmp0_ = separator;
	if (_tmp0_ == NULL) {
		separator = "";
	}
	_tmp3_ = str_array;
	_tmp3__length1 = str_array_length1;
	if (_tmp3_ != NULL) {
		_tmp2_ = TRUE;
	} else {
		gchar** _tmp4_;
		gint _tmp4__length1;
		_tmp4_ = str_array;
		_tmp4__length1 = str_array_length1;
		_tmp2_ = _tmp4__length1 > 0;
	}
	if (_tmp2_) {
		_tmp1_ = TRUE;
	} else {
		gboolean _tmp5_ = FALSE;
		gchar** _tmp6_;
		gint _tmp6__length1;
		_tmp6_ = str_array;
		_tmp6__length1 = str_array_length1;
		if (_tmp6__length1 == -1) {
			gchar** _tmp7_;
			gint _tmp7__length1;
			const gchar* _tmp8_;
			_tmp7_ = str_array;
			_tmp7__length1 = str_array_length1;
			_tmp8_ = _tmp7_[0];
			_tmp5_ = _tmp8_ != NULL;
		} else {
			_tmp5_ = FALSE;
		}
		_tmp1_ = _tmp5_;
	}
	if (_tmp1_) {
		gint i = 0;
		gsize len = 0UL;
		gint _tmp31_;
		gint _tmp33_;
		gint _tmp34_;
		gsize _tmp35_;
		const gchar* _tmp36_;
		gint _tmp37_;
		gint _tmp38_;
		gint _tmp39_;
		const gchar* res = NULL;
		gsize _tmp40_;
		void* _tmp41_;
		void* ptr = NULL;
		const gchar* _tmp42_;
		gchar** _tmp43_;
		gint _tmp43__length1;
		const gchar* _tmp44_;
		void* _tmp45_;
		const gchar* _tmp62_;
		len = (gsize) 1;
		{
			gboolean _tmp9_ = FALSE;
			i = 0;
			_tmp9_ = TRUE;
			while (TRUE) {
				gboolean _tmp11_ = FALSE;
				gboolean _tmp12_ = FALSE;
				gchar** _tmp13_;
				gint _tmp13__length1;
				gint _tmp21_ = 0;
				gchar** _tmp22_;
				gint _tmp22__length1;
				gint _tmp23_;
				const gchar* _tmp24_;
				gsize _tmp30_;
				if (!_tmp9_) {
					gint _tmp10_;
					_tmp10_ = i;
					i = _tmp10_ + 1;
				}
				_tmp9_ = FALSE;
				_tmp13_ = str_array;
				_tmp13__length1 = str_array_length1;
				if (_tmp13__length1 != -1) {
					gint _tmp14_;
					gchar** _tmp15_;
					gint _tmp15__length1;
					_tmp14_ = i;
					_tmp15_ = str_array;
					_tmp15__length1 = str_array_length1;
					_tmp12_ = _tmp14_ < _tmp15__length1;
				} else {
					_tmp12_ = FALSE;
				}
				if (_tmp12_) {
					_tmp11_ = TRUE;
				} else {
					gboolean _tmp16_ = FALSE;
					gchar** _tmp17_;
					gint _tmp17__length1;
					_tmp17_ = str_array;
					_tmp17__length1 = str_array_length1;
					if (_tmp17__length1 == -1) {
						gchar** _tmp18_;
						gint _tmp18__length1;
						gint _tmp19_;
						const gchar* _tmp20_;
						_tmp18_ = str_array;
						_tmp18__length1 = str_array_length1;
						_tmp19_ = i;
						_tmp20_ = _tmp18_[_tmp19_];
						_tmp16_ = _tmp20_ != NULL;
					} else {
						_tmp16_ = FALSE;
					}
					_tmp11_ = _tmp16_;
				}
				if (!_tmp11_) {
					break;
				}
				_tmp22_ = str_array;
				_tmp22__length1 = str_array_length1;
				_tmp23_ = i;
				_tmp24_ = _tmp22_[_tmp23_];
				if (_tmp24_ != NULL) {
					gchar** _tmp25_;
					gint _tmp25__length1;
					gint _tmp26_;
					const gchar* _tmp27_;
					gint _tmp28_;
					gint _tmp29_;
					_tmp25_ = str_array;
					_tmp25__length1 = str_array_length1;
					_tmp26_ = i;
					_tmp27_ = _tmp25_[_tmp26_];
					_tmp28_ = strlen ((const gchar*) _tmp27_);
					_tmp29_ = _tmp28_;
					_tmp21_ = _tmp29_;
				} else {
					_tmp21_ = 0;
				}
				_tmp30_ = len;
				len = _tmp30_ + _tmp21_;
			}
		}
		_tmp31_ = i;
		if (_tmp31_ == 0) {
			gchar* _tmp32_;
			_tmp32_ = g_strdup ("");
			result = _tmp32_;
			return result;
		}
		_tmp33_ = i;
		str_array_length1 = _tmp33_;
		_tmp34_ = str_array_length1;
		_tmp35_ = len;
		_tmp36_ = separator;
		_tmp37_ = strlen ((const gchar*) _tmp36_);
		_tmp38_ = _tmp37_;
		_tmp39_ = i;
		len = _tmp35_ + (_tmp38_ * (_tmp39_ - 1));
		_tmp40_ = len;
		_tmp41_ = g_malloc (_tmp40_);
		res = _tmp41_;
		_tmp42_ = res;
		_tmp43_ = str_array;
		_tmp43__length1 = str_array_length1;
		_tmp44_ = _tmp43_[0];
		_tmp45_ = g_stpcpy ((void*) _tmp42_, (const gchar*) _tmp44_);
		ptr = _tmp45_;
		{
			gboolean _tmp46_ = FALSE;
			i = 1;
			_tmp46_ = TRUE;
			while (TRUE) {
				gint _tmp48_;
				gchar** _tmp49_;
				gint _tmp49__length1;
				void* _tmp50_;
				const gchar* _tmp51_;
				void* _tmp52_;
				const gchar* _tmp53_ = NULL;
				gchar** _tmp54_;
				gint _tmp54__length1;
				gint _tmp55_;
				const gchar* _tmp56_;
				void* _tmp60_;
				void* _tmp61_;
				if (!_tmp46_) {
					gint _tmp47_;
					_tmp47_ = i;
					i = _tmp47_ + 1;
				}
				_tmp46_ = FALSE;
				_tmp48_ = i;
				_tmp49_ = str_array;
				_tmp49__length1 = str_array_length1;
				if (!(_tmp48_ < _tmp49__length1)) {
					break;
				}
				_tmp50_ = ptr;
				_tmp51_ = separator;
				_tmp52_ = g_stpcpy (_tmp50_, (const gchar*) _tmp51_);
				ptr = _tmp52_;
				_tmp54_ = str_array;
				_tmp54__length1 = str_array_length1;
				_tmp55_ = i;
				_tmp56_ = _tmp54_[_tmp55_];
				if (_tmp56_ != NULL) {
					gchar** _tmp57_;
					gint _tmp57__length1;
					gint _tmp58_;
					const gchar* _tmp59_;
					_tmp57_ = str_array;
					_tmp57__length1 = str_array_length1;
					_tmp58_ = i;
					_tmp59_ = _tmp57_[_tmp58_];
					_tmp53_ = (const gchar*) _tmp59_;
				} else {
					_tmp53_ = "";
				}
				_tmp60_ = ptr;
				_tmp61_ = g_stpcpy (_tmp60_, _tmp53_);
				ptr = _tmp61_;
			}
		}
		_tmp62_ = res;
		res = NULL;
		result = (gchar*) _tmp62_;
		return result;
	} else {
		gchar* _tmp63_;
		_tmp63_ = g_strdup ("");
		result = _tmp63_;
		return result;
	}
}


Guid guid_Parse (const gchar* v4) {
	Guid result = {0};
	gchar* s = NULL;
	const gchar* _tmp0_;
	gchar** _tmp1_;
	gchar** _tmp2_;
	gchar** _tmp3_;
	gint _tmp3__length1;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gint _tmp6_;
	gint _tmp7_;
	gchar* b = NULL;
	guint8 res[16] = {0};
	guint32 d1 = 0U;
	guint8 _tmp100_;
	guint32 _tmp101_;
	guint8 _tmp102_;
	guint32 _tmp103_;
	guint8 _tmp104_;
	guint32 _tmp105_;
	guint8 _tmp106_;
	guint16 d2 = 0U;
	guint8 _tmp107_;
	guint16 _tmp108_;
	guint8 _tmp109_;
	guint16 d3 = 0U;
	guint8 _tmp110_;
	guint16 _tmp111_;
	guint8 _tmp112_;
	guint32 _tmp113_;
	guint16 _tmp114_;
	guint16 _tmp115_;
	guint8 _tmp116_;
	guint8 _tmp117_;
	guint8 _tmp118_;
	guint8 _tmp119_;
	guint8 _tmp120_;
	guint8 _tmp121_;
	guint8 _tmp122_;
	guint8 _tmp123_;
	guint8 _tmp124_[8];
	Guid _tmp125_ = {0};
	GError * _inner_error_ = NULL;
	_tmp0_ = v4;
	_tmp2_ = _tmp1_ = g_strsplit (_tmp0_, "-", 0);
	_tmp3_ = _tmp2_;
	_tmp3__length1 = _vala_array_length (_tmp1_);
	_tmp4_ = _vala_g_strjoinv ("", _tmp3_, _vala_array_length (_tmp1_));
	_tmp5_ = _tmp4_;
	_tmp3_ = (_vala_array_free (_tmp3_, _tmp3__length1, (GDestroyNotify) g_free), NULL);
	s = _tmp5_;
	_tmp6_ = strlen (s);
	_tmp7_ = _tmp6_;
	if (_tmp7_ != 32) {
		const gchar* _tmp8_;
		GError* _tmp9_;
		Guid _tmp10_ = {0};
		_tmp8_ = v4;
		_tmp9_ = g_error_new_literal (GUID_EXCEPTION, GUID_EXCEPTION_StringTooShort, _tmp8_);
		_inner_error_ = _tmp9_;
		_g_free0 (s);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return _tmp10_;
	}
	b = (gchar*) s;
	{
		gint i = 0;
		gint p = 0;
		i = 0;
		p = 0;
		{
			gboolean _tmp11_ = FALSE;
			_tmp11_ = TRUE;
			while (TRUE) {
				gint _tmp13_;
				gboolean _tmp14_ = FALSE;
				gchar* _tmp15_;
				gint _tmp16_;
				gchar _tmp17_;
				gint _tmp53_;
				gboolean _tmp54_ = FALSE;
				gchar* _tmp55_;
				gint _tmp56_;
				gchar _tmp57_;
				gint _tmp99_;
				if (!_tmp11_) {
					gint _tmp12_;
					_tmp12_ = i;
					i = _tmp12_ + 1;
				}
				_tmp11_ = FALSE;
				_tmp13_ = i;
				if (!(_tmp13_ < 16)) {
					break;
				}
				_tmp15_ = b;
				_tmp16_ = p;
				_tmp17_ = _tmp15_[_tmp16_];
				if (_tmp17_ >= '0') {
					gchar* _tmp18_;
					gint _tmp19_;
					gchar _tmp20_;
					_tmp18_ = b;
					_tmp19_ = p;
					_tmp20_ = _tmp18_[_tmp19_];
					_tmp14_ = _tmp20_ <= '9';
				} else {
					_tmp14_ = FALSE;
				}
				if (_tmp14_) {
					gint _tmp21_;
					gchar* _tmp22_;
					gint _tmp23_;
					gchar _tmp24_;
					guint8 _tmp25_;
					_tmp21_ = i;
					_tmp22_ = b;
					_tmp23_ = p;
					_tmp24_ = _tmp22_[_tmp23_];
					res[_tmp21_] = (guint8) (_tmp24_ - '0');
					_tmp25_ = res[_tmp21_];
				} else {
					gboolean _tmp26_ = FALSE;
					gchar* _tmp27_;
					gint _tmp28_;
					gchar _tmp29_;
					_tmp27_ = b;
					_tmp28_ = p;
					_tmp29_ = _tmp27_[_tmp28_];
					if (_tmp29_ >= 'a') {
						gchar* _tmp30_;
						gint _tmp31_;
						gchar _tmp32_;
						_tmp30_ = b;
						_tmp31_ = p;
						_tmp32_ = _tmp30_[_tmp31_];
						_tmp26_ = _tmp32_ <= 'f';
					} else {
						_tmp26_ = FALSE;
					}
					if (_tmp26_) {
						gint _tmp33_;
						gchar* _tmp34_;
						gint _tmp35_;
						gchar _tmp36_;
						guint8 _tmp37_;
						_tmp33_ = i;
						_tmp34_ = b;
						_tmp35_ = p;
						_tmp36_ = _tmp34_[_tmp35_];
						res[_tmp33_] = (guint8) ((_tmp36_ - 'a') + 10);
						_tmp37_ = res[_tmp33_];
					} else {
						gboolean _tmp38_ = FALSE;
						gchar* _tmp39_;
						gint _tmp40_;
						gchar _tmp41_;
						_tmp39_ = b;
						_tmp40_ = p;
						_tmp41_ = _tmp39_[_tmp40_];
						if (_tmp41_ >= 'A') {
							gchar* _tmp42_;
							gint _tmp43_;
							gchar _tmp44_;
							_tmp42_ = b;
							_tmp43_ = p;
							_tmp44_ = _tmp42_[_tmp43_];
							_tmp38_ = _tmp44_ <= 'F';
						} else {
							_tmp38_ = FALSE;
						}
						if (_tmp38_) {
							gint _tmp45_;
							gchar* _tmp46_;
							gint _tmp47_;
							gchar _tmp48_;
							guint8 _tmp49_;
							_tmp45_ = i;
							_tmp46_ = b;
							_tmp47_ = p;
							_tmp48_ = _tmp46_[_tmp47_];
							res[_tmp45_] = (guint8) ((_tmp48_ - 'A') + 10);
							_tmp49_ = res[_tmp45_];
						} else {
							const gchar* _tmp50_;
							GError* _tmp51_;
							Guid _tmp52_ = {0};
							_tmp50_ = v4;
							_tmp51_ = g_error_new_literal (GUID_EXCEPTION, GUID_EXCEPTION_InvalidHexDigit, _tmp50_);
							_inner_error_ = _tmp51_;
							_g_free0 (s);
							g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
							g_clear_error (&_inner_error_);
							return _tmp52_;
						}
					}
				}
				_tmp53_ = p;
				p = _tmp53_ + 1;
				_tmp55_ = b;
				_tmp56_ = p;
				_tmp57_ = _tmp55_[_tmp56_];
				if (_tmp57_ >= '0') {
					gchar* _tmp58_;
					gint _tmp59_;
					gchar _tmp60_;
					_tmp58_ = b;
					_tmp59_ = p;
					_tmp60_ = _tmp58_[_tmp59_];
					_tmp54_ = _tmp60_ <= '9';
				} else {
					_tmp54_ = FALSE;
				}
				if (_tmp54_) {
					gint _tmp61_;
					gint _tmp62_;
					guint8 _tmp63_;
					gchar* _tmp64_;
					gint _tmp65_;
					gchar _tmp66_;
					guint8 _tmp67_;
					_tmp61_ = i;
					_tmp62_ = i;
					_tmp63_ = res[_tmp62_];
					_tmp64_ = b;
					_tmp65_ = p;
					_tmp66_ = _tmp64_[_tmp65_];
					res[_tmp61_] = (guint8) (((_tmp63_ * 16) + _tmp66_) - '0');
					_tmp67_ = res[_tmp61_];
				} else {
					gboolean _tmp68_ = FALSE;
					gchar* _tmp69_;
					gint _tmp70_;
					gchar _tmp71_;
					_tmp69_ = b;
					_tmp70_ = p;
					_tmp71_ = _tmp69_[_tmp70_];
					if (_tmp71_ >= 'a') {
						gchar* _tmp72_;
						gint _tmp73_;
						gchar _tmp74_;
						_tmp72_ = b;
						_tmp73_ = p;
						_tmp74_ = _tmp72_[_tmp73_];
						_tmp68_ = _tmp74_ <= 'f';
					} else {
						_tmp68_ = FALSE;
					}
					if (_tmp68_) {
						gint _tmp75_;
						gint _tmp76_;
						guint8 _tmp77_;
						gchar* _tmp78_;
						gint _tmp79_;
						gchar _tmp80_;
						guint8 _tmp81_;
						_tmp75_ = i;
						_tmp76_ = i;
						_tmp77_ = res[_tmp76_];
						_tmp78_ = b;
						_tmp79_ = p;
						_tmp80_ = _tmp78_[_tmp79_];
						res[_tmp75_] = (guint8) ((((_tmp77_ * 16) + _tmp80_) - 'a') + 10);
						_tmp81_ = res[_tmp75_];
					} else {
						gboolean _tmp82_ = FALSE;
						gchar* _tmp83_;
						gint _tmp84_;
						gchar _tmp85_;
						_tmp83_ = b;
						_tmp84_ = p;
						_tmp85_ = _tmp83_[_tmp84_];
						if (_tmp85_ >= 'A') {
							gchar* _tmp86_;
							gint _tmp87_;
							gchar _tmp88_;
							_tmp86_ = b;
							_tmp87_ = p;
							_tmp88_ = _tmp86_[_tmp87_];
							_tmp82_ = _tmp88_ <= 'F';
						} else {
							_tmp82_ = FALSE;
						}
						if (_tmp82_) {
							gint _tmp89_;
							gint _tmp90_;
							guint8 _tmp91_;
							gchar* _tmp92_;
							gint _tmp93_;
							gchar _tmp94_;
							guint8 _tmp95_;
							_tmp89_ = i;
							_tmp90_ = i;
							_tmp91_ = res[_tmp90_];
							_tmp92_ = b;
							_tmp93_ = p;
							_tmp94_ = _tmp92_[_tmp93_];
							res[_tmp89_] = (guint8) ((((_tmp91_ * 16) + _tmp94_) - 'A') + 10);
							_tmp95_ = res[_tmp89_];
						} else {
							const gchar* _tmp96_;
							GError* _tmp97_;
							Guid _tmp98_ = {0};
							_tmp96_ = v4;
							_tmp97_ = g_error_new_literal (GUID_EXCEPTION, GUID_EXCEPTION_InvalidHexDigit, _tmp96_);
							_inner_error_ = _tmp97_;
							_g_free0 (s);
							g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
							g_clear_error (&_inner_error_);
							return _tmp98_;
						}
					}
				}
				_tmp99_ = p;
				p = _tmp99_ + 1;
			}
		}
	}
	_tmp100_ = res[0];
	d1 = (guint32) _tmp100_;
	_tmp101_ = d1;
	_tmp102_ = res[1];
	d1 = (_tmp101_ << 8) | _tmp102_;
	_tmp103_ = d1;
	_tmp104_ = res[2];
	d1 = (_tmp103_ << 8) | _tmp104_;
	_tmp105_ = d1;
	_tmp106_ = res[3];
	d1 = (_tmp105_ << 8) | _tmp106_;
	_tmp107_ = res[4];
	d2 = (guint16) _tmp107_;
	_tmp108_ = d2;
	_tmp109_ = res[5];
	d2 = (guint16) ((_tmp108_ << 8) | _tmp109_);
	_tmp110_ = res[6];
	d3 = (guint16) _tmp110_;
	_tmp111_ = d3;
	_tmp112_ = res[7];
	d3 = (guint16) ((_tmp111_ << 8) | _tmp112_);
	_tmp113_ = d1;
	_tmp114_ = d2;
	_tmp115_ = d3;
	_tmp116_ = res[8];
	_tmp117_ = res[9];
	_tmp118_ = res[10];
	_tmp119_ = res[11];
	_tmp120_ = res[12];
	_tmp121_ = res[13];
	_tmp122_ = res[14];
	_tmp123_ = res[15];
	_tmp124_[0] = _tmp116_;
	_tmp124_[1] = _tmp117_;
	_tmp124_[2] = _tmp118_;
	_tmp124_[3] = _tmp119_;
	_tmp124_[4] = _tmp120_;
	_tmp124_[5] = _tmp121_;
	_tmp124_[6] = _tmp122_;
	_tmp124_[7] = _tmp123_;
	memset (&_tmp125_, 0, sizeof (Guid));
	_tmp125_.data1 = _tmp113_;
	_tmp125_.data2 = _tmp114_;
	_tmp125_.data3 = _tmp115_;
	memcpy (_tmp125_.data4, _tmp124_, 8 * sizeof (guint8));
	result = _tmp125_;
	_g_free0 (s);
	return result;
}


Guid* guid_dup (const Guid* self) {
	Guid* dup;
	dup = g_new0 (Guid, 1);
	memcpy (dup, self, sizeof (Guid));
	return dup;
}


void guid_free (Guid* self) {
	g_free (self);
}


GType guid_get_type (void) {
	static volatile gsize guid_type_id__volatile = 0;
	if (g_once_init_enter (&guid_type_id__volatile)) {
		GType guid_type_id;
		guid_type_id = g_boxed_type_register_static ("Guid", (GBoxedCopyFunc) guid_dup, (GBoxedFreeFunc) guid_free);
		g_once_init_leave (&guid_type_id__volatile, guid_type_id);
	}
	return guid_type_id__volatile;
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


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



