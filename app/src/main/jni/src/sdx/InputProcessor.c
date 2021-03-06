/** updated by adriac */
/* InputProcessor.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from InputProcessor.vala, do not modify */

/*[Adriac:Sdx::InputProcessor:SdxInputProcessor:sdx_input_processor]*/
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

typedef struct _SdxInputProcessor SdxInputProcessor;

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



void sdx_input_processor_free (SdxInputProcessor * self);
static void sdx_input_processor_instance_init (SdxInputProcessor * self);
SdxInputProcessor* sdx_input_processor_retain (SdxInputProcessor* self);
void sdx_input_processor_release (SdxInputProcessor* self);
void sdx_input_processor_free (SdxInputProcessor* self);
SdxInputProcessor* sdx_input_processor_new (void);
static gboolean __lambda31_ (SdxInputProcessor* self, gint keycode);
static gboolean ___lambda31__sdx_input_processor_input_processor_key_down (gint keycode, gpointer self);
static gboolean __lambda32_ (SdxInputProcessor* self, gint keycode);
static gboolean ___lambda32__sdx_input_processor_input_processor_key_up (gint keycode, gpointer self);
static gboolean __lambda33_ (SdxInputProcessor* self, gchar character);
static gboolean ___lambda33__sdx_input_processor_input_processor_key_typed (gchar character, gpointer self);
static gboolean __lambda34_ (SdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
static gboolean ___lambda34__sdx_input_processor_input_processor_touch_down (gint x, gint y, gint pointer, gint button, gpointer self);
static gboolean __lambda35_ (SdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button);
static gboolean ___lambda35__sdx_input_processor_input_processor_touch_up (gint x, gint y, gint pointer, gint button, gpointer self);
static gboolean __lambda36_ (SdxInputProcessor* self, gint screenX, gint screenY, gint pointer);
static gboolean ___lambda36__sdx_input_processor_input_processor_touch_dragged (gint x, gint y, gint pointer, gpointer self);
static gboolean __lambda37_ (SdxInputProcessor* self, gint screenX, gint screenY);
static gboolean ___lambda37__sdx_input_processor_input_processor_mouse_moved (gint x, gint y, gpointer self);
static gboolean __lambda38_ (SdxInputProcessor* self, gint amount);
static gboolean ___lambda38__sdx_input_processor_input_processor_scrolled (gint amount, gpointer self);
SdxInputProcessor* sdx_input_processor_SetKeyDown (SdxInputProcessor* self, SdxInputProcessorInputProcessorKeyDown keyDown, void* keyDown_target);
SdxInputProcessor* sdx_input_processor_SetKeyUp (SdxInputProcessor* self, SdxInputProcessorInputProcessorKeyUp keyUp, void* keyUp_target);
SdxInputProcessor* sdx_input_processor_SetKeyTyped (SdxInputProcessor* self, SdxInputProcessorInputProcessorKeyTyped keyTyped, void* keyTyped_target);
SdxInputProcessor* sdx_input_processor_SetTouchDown (SdxInputProcessor* self, SdxInputProcessorInputProcessorTouchDown touchDown, void* touchDown_target);
SdxInputProcessor* sdx_input_processor_SetTouchUp (SdxInputProcessor* self, SdxInputProcessorInputProcessorTouchUp touchUp, void* touchUp_target);
SdxInputProcessor* sdx_input_processor_SetTouchDragged (SdxInputProcessor* self, SdxInputProcessorInputProcessorTouchDragged touchDragged, void* touchDragged_target);
SdxInputProcessor* sdx_input_processor_SetMouseMoved (SdxInputProcessor* self, SdxInputProcessorInputProcessorMouseMoved mouseMoved, void* mouseMoved_target);
SdxInputProcessor* sdx_input_processor_SetScrolled (SdxInputProcessor* self, SdxInputProcessorInputProcessorScrolled scrolled, void* scrolled_target);


SdxInputProcessor* sdx_input_processor_retain (SdxInputProcessor* self) {
	SdxInputProcessor* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->ref_count), 1);
	result = self;
	return result;
}


void sdx_input_processor_release (SdxInputProcessor* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->ref_count));
	if (_tmp0_) {
		sdx_input_processor_free (self);
	}
}


static gboolean __lambda31_ (SdxInputProcessor* self, gint keycode) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


static gboolean ___lambda31__sdx_input_processor_input_processor_key_down (gint keycode, gpointer self) {
	gboolean result;
	result = __lambda31_ ((SdxInputProcessor*) self, keycode);
	return result;
}


static gboolean __lambda32_ (SdxInputProcessor* self, gint keycode) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


static gboolean ___lambda32__sdx_input_processor_input_processor_key_up (gint keycode, gpointer self) {
	gboolean result;
	result = __lambda32_ ((SdxInputProcessor*) self, keycode);
	return result;
}


static gboolean __lambda33_ (SdxInputProcessor* self, gchar character) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


static gboolean ___lambda33__sdx_input_processor_input_processor_key_typed (gchar character, gpointer self) {
	gboolean result;
	result = __lambda33_ ((SdxInputProcessor*) self, character);
	return result;
}


static gboolean __lambda34_ (SdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


static gboolean ___lambda34__sdx_input_processor_input_processor_touch_down (gint x, gint y, gint pointer, gint button, gpointer self) {
	gboolean result;
	result = __lambda34_ ((SdxInputProcessor*) self, x, y, pointer, button);
	return result;
}


static gboolean __lambda35_ (SdxInputProcessor* self, gint screenX, gint screenY, gint pointer, gint button) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


static gboolean ___lambda35__sdx_input_processor_input_processor_touch_up (gint x, gint y, gint pointer, gint button, gpointer self) {
	gboolean result;
	result = __lambda35_ ((SdxInputProcessor*) self, x, y, pointer, button);
	return result;
}


static gboolean __lambda36_ (SdxInputProcessor* self, gint screenX, gint screenY, gint pointer) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


static gboolean ___lambda36__sdx_input_processor_input_processor_touch_dragged (gint x, gint y, gint pointer, gpointer self) {
	gboolean result;
	result = __lambda36_ ((SdxInputProcessor*) self, x, y, pointer);
	return result;
}


static gboolean __lambda37_ (SdxInputProcessor* self, gint screenX, gint screenY) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


static gboolean ___lambda37__sdx_input_processor_input_processor_mouse_moved (gint x, gint y, gpointer self) {
	gboolean result;
	result = __lambda37_ ((SdxInputProcessor*) self, x, y);
	return result;
}


static gboolean __lambda38_ (SdxInputProcessor* self, gint amount) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


static gboolean ___lambda38__sdx_input_processor_input_processor_scrolled (gint amount, gpointer self) {
	gboolean result;
	result = __lambda38_ ((SdxInputProcessor*) self, amount);
	return result;
}


SdxInputProcessor* sdx_input_processor_new (void) {
	SdxInputProcessor* self;
	self = g_slice_new0 (SdxInputProcessor);
	sdx_input_processor_instance_init (self);
	(self->KeyDown_target_destroy_notify == NULL) ? NULL : (self->KeyDown_target_destroy_notify (self->KeyDown_target), NULL);
	self->KeyDown = NULL;
	self->KeyDown_target = NULL;
	self->KeyDown_target_destroy_notify = NULL;
	self->KeyDown = ___lambda31__sdx_input_processor_input_processor_key_down;
	self->KeyDown_target = sdx_input_processor_retain (self);
	self->KeyDown_target_destroy_notify = sdx_input_processor_release;
	(self->KeyUp_target_destroy_notify == NULL) ? NULL : (self->KeyUp_target_destroy_notify (self->KeyUp_target), NULL);
	self->KeyUp = NULL;
	self->KeyUp_target = NULL;
	self->KeyUp_target_destroy_notify = NULL;
	self->KeyUp = ___lambda32__sdx_input_processor_input_processor_key_up;
	self->KeyUp_target = sdx_input_processor_retain (self);
	self->KeyUp_target_destroy_notify = sdx_input_processor_release;
	(self->KeyTyped_target_destroy_notify == NULL) ? NULL : (self->KeyTyped_target_destroy_notify (self->KeyTyped_target), NULL);
	self->KeyTyped = NULL;
	self->KeyTyped_target = NULL;
	self->KeyTyped_target_destroy_notify = NULL;
	self->KeyTyped = ___lambda33__sdx_input_processor_input_processor_key_typed;
	self->KeyTyped_target = sdx_input_processor_retain (self);
	self->KeyTyped_target_destroy_notify = sdx_input_processor_release;
	(self->TouchDown_target_destroy_notify == NULL) ? NULL : (self->TouchDown_target_destroy_notify (self->TouchDown_target), NULL);
	self->TouchDown = NULL;
	self->TouchDown_target = NULL;
	self->TouchDown_target_destroy_notify = NULL;
	self->TouchDown = ___lambda34__sdx_input_processor_input_processor_touch_down;
	self->TouchDown_target = sdx_input_processor_retain (self);
	self->TouchDown_target_destroy_notify = sdx_input_processor_release;
	(self->TouchUp_target_destroy_notify == NULL) ? NULL : (self->TouchUp_target_destroy_notify (self->TouchUp_target), NULL);
	self->TouchUp = NULL;
	self->TouchUp_target = NULL;
	self->TouchUp_target_destroy_notify = NULL;
	self->TouchUp = ___lambda35__sdx_input_processor_input_processor_touch_up;
	self->TouchUp_target = sdx_input_processor_retain (self);
	self->TouchUp_target_destroy_notify = sdx_input_processor_release;
	(self->TouchDragged_target_destroy_notify == NULL) ? NULL : (self->TouchDragged_target_destroy_notify (self->TouchDragged_target), NULL);
	self->TouchDragged = NULL;
	self->TouchDragged_target = NULL;
	self->TouchDragged_target_destroy_notify = NULL;
	self->TouchDragged = ___lambda36__sdx_input_processor_input_processor_touch_dragged;
	self->TouchDragged_target = sdx_input_processor_retain (self);
	self->TouchDragged_target_destroy_notify = sdx_input_processor_release;
	(self->MouseMoved_target_destroy_notify == NULL) ? NULL : (self->MouseMoved_target_destroy_notify (self->MouseMoved_target), NULL);
	self->MouseMoved = NULL;
	self->MouseMoved_target = NULL;
	self->MouseMoved_target_destroy_notify = NULL;
	self->MouseMoved = ___lambda37__sdx_input_processor_input_processor_mouse_moved;
	self->MouseMoved_target = sdx_input_processor_retain (self);
	self->MouseMoved_target_destroy_notify = sdx_input_processor_release;
	(self->Scrolled_target_destroy_notify == NULL) ? NULL : (self->Scrolled_target_destroy_notify (self->Scrolled_target), NULL);
	self->Scrolled = NULL;
	self->Scrolled_target = NULL;
	self->Scrolled_target_destroy_notify = NULL;
	self->Scrolled = ___lambda38__sdx_input_processor_input_processor_scrolled;
	self->Scrolled_target = sdx_input_processor_retain (self);
	self->Scrolled_target_destroy_notify = sdx_input_processor_release;
	return self;
}


static gpointer _sdx_input_processor_retain0 (gpointer self) {
	return self ? sdx_input_processor_retain (self) : NULL;
}


SdxInputProcessor* sdx_input_processor_SetKeyDown (SdxInputProcessor* self, SdxInputProcessorInputProcessorKeyDown keyDown, void* keyDown_target) {
	SdxInputProcessor* result = NULL;
	SdxInputProcessorInputProcessorKeyDown _tmp0_;
	void* _tmp0__target;
	SdxInputProcessor* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = keyDown;
	_tmp0__target = keyDown_target;
	(self->KeyDown_target_destroy_notify == NULL) ? NULL : (self->KeyDown_target_destroy_notify (self->KeyDown_target), NULL);
	self->KeyDown = NULL;
	self->KeyDown_target = NULL;
	self->KeyDown_target_destroy_notify = NULL;
	self->KeyDown = _tmp0_;
	self->KeyDown_target = _tmp0__target;
	self->KeyDown_target_destroy_notify = NULL;
	_tmp1_ = _sdx_input_processor_retain0 (self);
	result = _tmp1_;
	return result;
}


SdxInputProcessor* sdx_input_processor_SetKeyUp (SdxInputProcessor* self, SdxInputProcessorInputProcessorKeyUp keyUp, void* keyUp_target) {
	SdxInputProcessor* result = NULL;
	SdxInputProcessorInputProcessorKeyUp _tmp0_;
	void* _tmp0__target;
	SdxInputProcessor* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = keyUp;
	_tmp0__target = keyUp_target;
	(self->KeyUp_target_destroy_notify == NULL) ? NULL : (self->KeyUp_target_destroy_notify (self->KeyUp_target), NULL);
	self->KeyUp = NULL;
	self->KeyUp_target = NULL;
	self->KeyUp_target_destroy_notify = NULL;
	self->KeyUp = _tmp0_;
	self->KeyUp_target = _tmp0__target;
	self->KeyUp_target_destroy_notify = NULL;
	_tmp1_ = _sdx_input_processor_retain0 (self);
	result = _tmp1_;
	return result;
}


SdxInputProcessor* sdx_input_processor_SetKeyTyped (SdxInputProcessor* self, SdxInputProcessorInputProcessorKeyTyped keyTyped, void* keyTyped_target) {
	SdxInputProcessor* result = NULL;
	SdxInputProcessorInputProcessorKeyTyped _tmp0_;
	void* _tmp0__target;
	SdxInputProcessor* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = keyTyped;
	_tmp0__target = keyTyped_target;
	(self->KeyTyped_target_destroy_notify == NULL) ? NULL : (self->KeyTyped_target_destroy_notify (self->KeyTyped_target), NULL);
	self->KeyTyped = NULL;
	self->KeyTyped_target = NULL;
	self->KeyTyped_target_destroy_notify = NULL;
	self->KeyTyped = _tmp0_;
	self->KeyTyped_target = _tmp0__target;
	self->KeyTyped_target_destroy_notify = NULL;
	_tmp1_ = _sdx_input_processor_retain0 (self);
	result = _tmp1_;
	return result;
}


SdxInputProcessor* sdx_input_processor_SetTouchDown (SdxInputProcessor* self, SdxInputProcessorInputProcessorTouchDown touchDown, void* touchDown_target) {
	SdxInputProcessor* result = NULL;
	SdxInputProcessorInputProcessorTouchDown _tmp0_;
	void* _tmp0__target;
	SdxInputProcessor* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = touchDown;
	_tmp0__target = touchDown_target;
	(self->TouchDown_target_destroy_notify == NULL) ? NULL : (self->TouchDown_target_destroy_notify (self->TouchDown_target), NULL);
	self->TouchDown = NULL;
	self->TouchDown_target = NULL;
	self->TouchDown_target_destroy_notify = NULL;
	self->TouchDown = _tmp0_;
	self->TouchDown_target = _tmp0__target;
	self->TouchDown_target_destroy_notify = NULL;
	_tmp1_ = _sdx_input_processor_retain0 (self);
	result = _tmp1_;
	return result;
}


SdxInputProcessor* sdx_input_processor_SetTouchUp (SdxInputProcessor* self, SdxInputProcessorInputProcessorTouchUp touchUp, void* touchUp_target) {
	SdxInputProcessor* result = NULL;
	SdxInputProcessorInputProcessorTouchUp _tmp0_;
	void* _tmp0__target;
	SdxInputProcessor* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = touchUp;
	_tmp0__target = touchUp_target;
	(self->TouchUp_target_destroy_notify == NULL) ? NULL : (self->TouchUp_target_destroy_notify (self->TouchUp_target), NULL);
	self->TouchUp = NULL;
	self->TouchUp_target = NULL;
	self->TouchUp_target_destroy_notify = NULL;
	self->TouchUp = _tmp0_;
	self->TouchUp_target = _tmp0__target;
	self->TouchUp_target_destroy_notify = NULL;
	_tmp1_ = _sdx_input_processor_retain0 (self);
	result = _tmp1_;
	return result;
}


SdxInputProcessor* sdx_input_processor_SetTouchDragged (SdxInputProcessor* self, SdxInputProcessorInputProcessorTouchDragged touchDragged, void* touchDragged_target) {
	SdxInputProcessor* result = NULL;
	SdxInputProcessorInputProcessorTouchDragged _tmp0_;
	void* _tmp0__target;
	SdxInputProcessor* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = touchDragged;
	_tmp0__target = touchDragged_target;
	(self->TouchDragged_target_destroy_notify == NULL) ? NULL : (self->TouchDragged_target_destroy_notify (self->TouchDragged_target), NULL);
	self->TouchDragged = NULL;
	self->TouchDragged_target = NULL;
	self->TouchDragged_target_destroy_notify = NULL;
	self->TouchDragged = _tmp0_;
	self->TouchDragged_target = _tmp0__target;
	self->TouchDragged_target_destroy_notify = NULL;
	_tmp1_ = _sdx_input_processor_retain0 (self);
	result = _tmp1_;
	return result;
}


SdxInputProcessor* sdx_input_processor_SetMouseMoved (SdxInputProcessor* self, SdxInputProcessorInputProcessorMouseMoved mouseMoved, void* mouseMoved_target) {
	SdxInputProcessor* result = NULL;
	SdxInputProcessorInputProcessorMouseMoved _tmp0_;
	void* _tmp0__target;
	SdxInputProcessor* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = mouseMoved;
	_tmp0__target = mouseMoved_target;
	(self->MouseMoved_target_destroy_notify == NULL) ? NULL : (self->MouseMoved_target_destroy_notify (self->MouseMoved_target), NULL);
	self->MouseMoved = NULL;
	self->MouseMoved_target = NULL;
	self->MouseMoved_target_destroy_notify = NULL;
	self->MouseMoved = _tmp0_;
	self->MouseMoved_target = _tmp0__target;
	self->MouseMoved_target_destroy_notify = NULL;
	_tmp1_ = _sdx_input_processor_retain0 (self);
	result = _tmp1_;
	return result;
}


SdxInputProcessor* sdx_input_processor_SetScrolled (SdxInputProcessor* self, SdxInputProcessorInputProcessorScrolled scrolled, void* scrolled_target) {
	SdxInputProcessor* result = NULL;
	SdxInputProcessorInputProcessorScrolled _tmp0_;
	void* _tmp0__target;
	SdxInputProcessor* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = scrolled;
	_tmp0__target = scrolled_target;
	(self->Scrolled_target_destroy_notify == NULL) ? NULL : (self->Scrolled_target_destroy_notify (self->Scrolled_target), NULL);
	self->Scrolled = NULL;
	self->Scrolled_target = NULL;
	self->Scrolled_target_destroy_notify = NULL;
	self->Scrolled = _tmp0_;
	self->Scrolled_target = _tmp0__target;
	self->Scrolled_target_destroy_notify = NULL;
	_tmp1_ = _sdx_input_processor_retain0 (self);
	result = _tmp1_;
	return result;
}


static void sdx_input_processor_instance_init (SdxInputProcessor * self) {
	self->ref_count = 1;
}


void sdx_input_processor_free (SdxInputProcessor * self) {
	(self->KeyDown_target_destroy_notify == NULL) ? NULL : (self->KeyDown_target_destroy_notify (self->KeyDown_target), NULL);
	self->KeyDown = NULL;
	self->KeyDown_target = NULL;
	self->KeyDown_target_destroy_notify = NULL;
	(self->KeyUp_target_destroy_notify == NULL) ? NULL : (self->KeyUp_target_destroy_notify (self->KeyUp_target), NULL);
	self->KeyUp = NULL;
	self->KeyUp_target = NULL;
	self->KeyUp_target_destroy_notify = NULL;
	(self->KeyTyped_target_destroy_notify == NULL) ? NULL : (self->KeyTyped_target_destroy_notify (self->KeyTyped_target), NULL);
	self->KeyTyped = NULL;
	self->KeyTyped_target = NULL;
	self->KeyTyped_target_destroy_notify = NULL;
	(self->TouchDown_target_destroy_notify == NULL) ? NULL : (self->TouchDown_target_destroy_notify (self->TouchDown_target), NULL);
	self->TouchDown = NULL;
	self->TouchDown_target = NULL;
	self->TouchDown_target_destroy_notify = NULL;
	(self->TouchUp_target_destroy_notify == NULL) ? NULL : (self->TouchUp_target_destroy_notify (self->TouchUp_target), NULL);
	self->TouchUp = NULL;
	self->TouchUp_target = NULL;
	self->TouchUp_target_destroy_notify = NULL;
	(self->TouchDragged_target_destroy_notify == NULL) ? NULL : (self->TouchDragged_target_destroy_notify (self->TouchDragged_target), NULL);
	self->TouchDragged = NULL;
	self->TouchDragged_target = NULL;
	self->TouchDragged_target_destroy_notify = NULL;
	(self->MouseMoved_target_destroy_notify == NULL) ? NULL : (self->MouseMoved_target_destroy_notify (self->MouseMoved_target), NULL);
	self->MouseMoved = NULL;
	self->MouseMoved_target = NULL;
	self->MouseMoved_target_destroy_notify = NULL;
	(self->Scrolled_target_destroy_notify == NULL) ? NULL : (self->Scrolled_target_destroy_notify (self->Scrolled_target), NULL);
	self->Scrolled = NULL;
	self->Scrolled_target = NULL;
	self->Scrolled_target_destroy_notify = NULL;
	g_slice_free (SdxInputProcessor, self);
}




