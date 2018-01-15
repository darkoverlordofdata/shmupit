/** updated by adriac */
/* InputMultiplexer.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from InputMultiplexer.vala, do not modify */

/*[Adriac:Sdx::InputMultiplexer:SdxInputMultiplexer:sdx_input_multiplexer]*/
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

typedef struct _SdxInputMultiplexer SdxInputMultiplexer;
typedef struct _SdxInputProcessor SdxInputProcessor;
#define _g_ptr_array_unref0(var) ((var == NULL) ? NULL : (var = (g_ptr_array_unref (var), NULL)))

struct _SdxInputMultiplexer {
	gint ref_count;
	GPtrArray* processors;
};

typedef gboolean (*SdxInputProcessorInputProcessorKeyDown) (gint keycode, void* user_data);
typedef gboolean (*SdxInputProcessorInputProcessorKeyUp) (gint keycode, void* user_data);
typedef gboolean (*SdxInputProcessorInputProcessorKeyTyped) (gchar character, void* user_data);
typedef gboolean (*SdxInputProcessorInputProcessorTouchDown) (gint x, gint y, gint pointer, gint button, void* user_data);
typedef gboolean (*SdxInputProcessorInputProcessorTouchUp) (gint x, gint y, gint pointer, gint button, void* user_data);
typedef gboolean (*SdxInputProcessorInputProcessorTouchDragged) (gint x, gint y, gint pointer, void* user_data);
typedef gboolean (*SdxInputProcessorInputProcessorMouseMoved) (gint x, gint y, void* user_data);
typedef gboolean (*SdxInputProcessorInputProcessorScrolled) (gint amount, void* user_data);
struct _SdxInputProcessor {
	gint ref_count;
	SdxInputProcessorInputProcessorKeyDown KeyDown;
	gpointer KeyDown_target;
	GDestroyNotify KeyDown_target_destroy_notify;
	SdxInputProcessorInputProcessorKeyUp KeyUp;
	gpointer KeyUp_target;
	GDestroyNotify KeyUp_target_destroy_notify;
	SdxInputProcessorInputProcessorKeyTyped KeyTyped;
	gpointer KeyTyped_target;
	GDestroyNotify KeyTyped_target_destroy_notify;
	SdxInputProcessorInputProcessorTouchDown TouchDown;
	gpointer TouchDown_target;
	GDestroyNotify TouchDown_target_destroy_notify;
	SdxInputProcessorInputProcessorTouchUp TouchUp;
	gpointer TouchUp_target;
	GDestroyNotify TouchUp_target_destroy_notify;
	SdxInputProcessorInputProcessorTouchDragged TouchDragged;
	gpointer TouchDragged_target;
	GDestroyNotify TouchDragged_target_destroy_notify;
	SdxInputProcessorInputProcessorMouseMoved MouseMoved;
	gpointer MouseMoved_target;
	GDestroyNotify MouseMoved_target_destroy_notify;
	SdxInputProcessorInputProcessorScrolled Scrolled;
	gpointer Scrolled_target;
	GDestroyNotify Scrolled_target_destroy_notify;
};



void sdx_input_multiplexer_free (SdxInputMultiplexer * self);
void sdx_input_processor_free (SdxInputProcessor * self);
static void sdx_input_multiplexer_instance_init (SdxInputMultiplexer * self);
SdxInputMultiplexer* sdx_input_multiplexer_retain (SdxInputMultiplexer* self);
void sdx_input_multiplexer_release (SdxInputMultiplexer* self);
void sdx_input_multiplexer_free (SdxInputMultiplexer* self);
SdxInputMultiplexer* sdx_input_multiplexer_new (void);
// symtbl.2 sdx_input_processor
void sdx_input_processor_release (SdxInputProcessor* self);
void sdx_input_processor_free (SdxInputProcessor* self);
SdxInputProcessor* sdx_input_processor_retain (SdxInputProcessor* self);
static void _sdx_input_processor_release0_ (gpointer var);
void sdx_input_multiplexer_Add (SdxInputMultiplexer* self, SdxInputProcessor* processor);
void sdx_input_multiplexer_Remove (SdxInputMultiplexer* self, SdxInputProcessor* processor);
gboolean sdx_input_multiplexer_KeyDown (SdxInputMultiplexer* self, gint keycode);
gboolean sdx_input_multiplexer_KeyUp (SdxInputMultiplexer* self, gint keycode);
gboolean sdx_input_multiplexer_KeyTyped (SdxInputMultiplexer* self, gchar character);
gboolean sdx_input_multiplexer_TouchDown (SdxInputMultiplexer* self, gint x, gint y, gint pointer, gint button);
gboolean sdx_input_multiplexer_TouchUp (SdxInputMultiplexer* self, gint x, gint y, gint pointer, gint button);
gboolean sdx_input_multiplexer_TouchDragged (SdxInputMultiplexer* self, gint x, gint y, gint pointer);
gboolean sdx_input_multiplexer_MouseMoved (SdxInputMultiplexer* self, gint x, gint y);
gboolean sdx_input_multiplexer_Scrolled (SdxInputMultiplexer* self, gint amount);


SdxInputMultiplexer* sdx_input_multiplexer_retain (SdxInputMultiplexer* self) {
	SdxInputMultiplexer* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->ref_count), 1);
	result = self;
	return result;
}


void sdx_input_multiplexer_release (SdxInputMultiplexer* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->ref_count));
	if (_tmp0_) {
		sdx_input_multiplexer_free (self);
	}
}


// symtbl.2 sdx_input_processor
void sdx_input_processor_release (SdxInputProcessor* self);
void sdx_input_processor_free (SdxInputProcessor* self);
SdxInputProcessor* sdx_input_processor_retain (SdxInputProcessor* self);
static void _sdx_input_processor_release0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (sdx_input_processor_release (var), NULL));
}


SdxInputMultiplexer* sdx_input_multiplexer_new (void) {
	SdxInputMultiplexer* self;
	GPtrArray* _tmp0_;
	self = g_slice_new0 (SdxInputMultiplexer);
	sdx_input_multiplexer_instance_init (self);
	_tmp0_ = g_ptr_array_new_full ((guint) 4, _sdx_input_processor_release0_);
	_g_ptr_array_unref0 (self->processors);
	self->processors = _tmp0_;
	return self;
}


static gpointer _sdx_input_processor_retain0 (gpointer self) {
	return self ? sdx_input_processor_retain (self) : NULL;
}


void sdx_input_multiplexer_Add (SdxInputMultiplexer* self, SdxInputProcessor* processor) {
	GPtrArray* _tmp0_;
	SdxInputProcessor* _tmp1_;
	SdxInputProcessor* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (processor != NULL);
	_tmp0_ = self->processors;
	_tmp1_ = processor;
	_tmp2_ = _sdx_input_processor_retain0 (_tmp1_);
	g_ptr_array_add (_tmp0_, _tmp2_);
}


void sdx_input_multiplexer_Remove (SdxInputMultiplexer* self, SdxInputProcessor* processor) {
	GPtrArray* _tmp0_;
	SdxInputProcessor* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (processor != NULL);
	_tmp0_ = self->processors;
	_tmp1_ = processor;
	g_ptr_array_remove (_tmp0_, _tmp1_);
}


static gint g_ptr_array_get_length (GPtrArray* self) {
	gint result;
	guint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->len;
	result = (gint) _tmp0_;
	return result;
}


static void g_ptr_array_set_length (GPtrArray* self, gint value) {
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	g_ptr_array_set_size (self, _tmp0_);
}


gboolean sdx_input_multiplexer_KeyDown (SdxInputMultiplexer* self, gint keycode) {
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
				GPtrArray* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				GPtrArray* _tmp6_;
				gint _tmp7_;
				gconstpointer _tmp8_;
				SdxInputProcessorInputProcessorKeyDown _tmp9_;
				void* _tmp9__target;
				gint _tmp10_;
				gboolean _tmp11_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->processors;
				_tmp4_ = g_ptr_array_get_length (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = self->processors;
				_tmp7_ = i;
				_tmp8_ = g_ptr_array_index (_tmp6_, (guint) _tmp7_);
				_tmp9_ = ((SdxInputProcessor*) _tmp8_)->KeyDown;
				_tmp9__target = ((SdxInputProcessor*) _tmp8_)->KeyDown_target;
				_tmp10_ = keycode;
				_tmp11_ = _tmp9_ (_tmp10_, _tmp9__target);
				if (_tmp11_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_input_multiplexer_KeyUp (SdxInputMultiplexer* self, gint keycode) {
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
				GPtrArray* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				GPtrArray* _tmp6_;
				gint _tmp7_;
				gconstpointer _tmp8_;
				SdxInputProcessorInputProcessorKeyUp _tmp9_;
				void* _tmp9__target;
				gint _tmp10_;
				gboolean _tmp11_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->processors;
				_tmp4_ = g_ptr_array_get_length (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = self->processors;
				_tmp7_ = i;
				_tmp8_ = g_ptr_array_index (_tmp6_, (guint) _tmp7_);
				_tmp9_ = ((SdxInputProcessor*) _tmp8_)->KeyUp;
				_tmp9__target = ((SdxInputProcessor*) _tmp8_)->KeyUp_target;
				_tmp10_ = keycode;
				_tmp11_ = _tmp9_ (_tmp10_, _tmp9__target);
				if (_tmp11_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_input_multiplexer_KeyTyped (SdxInputMultiplexer* self, gchar character) {
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
				GPtrArray* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				GPtrArray* _tmp6_;
				gint _tmp7_;
				gconstpointer _tmp8_;
				SdxInputProcessorInputProcessorKeyTyped _tmp9_;
				void* _tmp9__target;
				gchar _tmp10_;
				gboolean _tmp11_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->processors;
				_tmp4_ = g_ptr_array_get_length (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = self->processors;
				_tmp7_ = i;
				_tmp8_ = g_ptr_array_index (_tmp6_, (guint) _tmp7_);
				_tmp9_ = ((SdxInputProcessor*) _tmp8_)->KeyTyped;
				_tmp9__target = ((SdxInputProcessor*) _tmp8_)->KeyTyped_target;
				_tmp10_ = character;
				_tmp11_ = _tmp9_ (_tmp10_, _tmp9__target);
				if (_tmp11_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_input_multiplexer_TouchDown (SdxInputMultiplexer* self, gint x, gint y, gint pointer, gint button) {
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
				GPtrArray* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				GPtrArray* _tmp6_;
				gint _tmp7_;
				gconstpointer _tmp8_;
				SdxInputProcessorInputProcessorTouchDown _tmp9_;
				void* _tmp9__target;
				gint _tmp10_;
				gint _tmp11_;
				gint _tmp12_;
				gint _tmp13_;
				gboolean _tmp14_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->processors;
				_tmp4_ = g_ptr_array_get_length (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = self->processors;
				_tmp7_ = i;
				_tmp8_ = g_ptr_array_index (_tmp6_, (guint) _tmp7_);
				_tmp9_ = ((SdxInputProcessor*) _tmp8_)->TouchDown;
				_tmp9__target = ((SdxInputProcessor*) _tmp8_)->TouchDown_target;
				_tmp10_ = x;
				_tmp11_ = y;
				_tmp12_ = pointer;
				_tmp13_ = button;
				_tmp14_ = _tmp9_ (_tmp10_, _tmp11_, _tmp12_, _tmp13_, _tmp9__target);
				if (_tmp14_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_input_multiplexer_TouchUp (SdxInputMultiplexer* self, gint x, gint y, gint pointer, gint button) {
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
				GPtrArray* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				GPtrArray* _tmp6_;
				gint _tmp7_;
				gconstpointer _tmp8_;
				SdxInputProcessorInputProcessorTouchUp _tmp9_;
				void* _tmp9__target;
				gint _tmp10_;
				gint _tmp11_;
				gint _tmp12_;
				gint _tmp13_;
				gboolean _tmp14_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->processors;
				_tmp4_ = g_ptr_array_get_length (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = self->processors;
				_tmp7_ = i;
				_tmp8_ = g_ptr_array_index (_tmp6_, (guint) _tmp7_);
				_tmp9_ = ((SdxInputProcessor*) _tmp8_)->TouchUp;
				_tmp9__target = ((SdxInputProcessor*) _tmp8_)->TouchUp_target;
				_tmp10_ = x;
				_tmp11_ = y;
				_tmp12_ = pointer;
				_tmp13_ = button;
				_tmp14_ = _tmp9_ (_tmp10_, _tmp11_, _tmp12_, _tmp13_, _tmp9__target);
				if (_tmp14_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_input_multiplexer_TouchDragged (SdxInputMultiplexer* self, gint x, gint y, gint pointer) {
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
				GPtrArray* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				GPtrArray* _tmp6_;
				gint _tmp7_;
				gconstpointer _tmp8_;
				SdxInputProcessorInputProcessorTouchDragged _tmp9_;
				void* _tmp9__target;
				gint _tmp10_;
				gint _tmp11_;
				gint _tmp12_;
				gboolean _tmp13_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->processors;
				_tmp4_ = g_ptr_array_get_length (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = self->processors;
				_tmp7_ = i;
				_tmp8_ = g_ptr_array_index (_tmp6_, (guint) _tmp7_);
				_tmp9_ = ((SdxInputProcessor*) _tmp8_)->TouchDragged;
				_tmp9__target = ((SdxInputProcessor*) _tmp8_)->TouchDragged_target;
				_tmp10_ = x;
				_tmp11_ = y;
				_tmp12_ = pointer;
				_tmp13_ = _tmp9_ (_tmp10_, _tmp11_, _tmp12_, _tmp9__target);
				if (_tmp13_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_input_multiplexer_MouseMoved (SdxInputMultiplexer* self, gint x, gint y) {
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
				GPtrArray* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				GPtrArray* _tmp6_;
				gint _tmp7_;
				gconstpointer _tmp8_;
				SdxInputProcessorInputProcessorMouseMoved _tmp9_;
				void* _tmp9__target;
				gint _tmp10_;
				gint _tmp11_;
				gboolean _tmp12_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->processors;
				_tmp4_ = g_ptr_array_get_length (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = self->processors;
				_tmp7_ = i;
				_tmp8_ = g_ptr_array_index (_tmp6_, (guint) _tmp7_);
				_tmp9_ = ((SdxInputProcessor*) _tmp8_)->MouseMoved;
				_tmp9__target = ((SdxInputProcessor*) _tmp8_)->MouseMoved_target;
				_tmp10_ = x;
				_tmp11_ = y;
				_tmp12_ = _tmp9_ (_tmp10_, _tmp11_, _tmp9__target);
				if (_tmp12_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean sdx_input_multiplexer_Scrolled (SdxInputMultiplexer* self, gint amount) {
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
				GPtrArray* _tmp3_;
				gint _tmp4_;
				gint _tmp5_;
				GPtrArray* _tmp6_;
				gint _tmp7_;
				gconstpointer _tmp8_;
				SdxInputProcessorInputProcessorScrolled _tmp9_;
				void* _tmp9__target;
				gint _tmp10_;
				gboolean _tmp11_;
				if (!_tmp0_) {
					gint _tmp1_;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->processors;
				_tmp4_ = g_ptr_array_get_length (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = self->processors;
				_tmp7_ = i;
				_tmp8_ = g_ptr_array_index (_tmp6_, (guint) _tmp7_);
				_tmp9_ = ((SdxInputProcessor*) _tmp8_)->Scrolled;
				_tmp9__target = ((SdxInputProcessor*) _tmp8_)->Scrolled_target;
				_tmp10_ = amount;
				_tmp11_ = _tmp9_ (_tmp10_, _tmp9__target);
				if (_tmp11_) {
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


static void sdx_input_multiplexer_instance_init (SdxInputMultiplexer * self) {
	self->ref_count = 1;
}


void sdx_input_multiplexer_free (SdxInputMultiplexer * self) {
	_g_ptr_array_unref0 (self->processors);
	g_slice_free (SdxInputMultiplexer, self);
}



