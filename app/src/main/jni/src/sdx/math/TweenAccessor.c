/** updated by adriac */
/* TweenAccessor.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from TweenAccessor.vala, do not modify */

/*[Adriac:Sdx.Math::TweenAccessor:SdxMathTweenAccessor:sdx_math_tween_accessor]*/
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
#include <float.h>
#include <math.h>

typedef struct _SdxMathTweenAccessor SdxMathTweenAccessor;

typedef gint (*SdxMathTweenAccessorGetValues) (void* target, gint tweenType, gfloat** returnValues, int* returnValues_length1, void* user_data);
typedef void (*SdxMathTweenAccessorSetValues) (void* target, gint tweenType, gfloat** newValues, int* newValues_length1, void* user_data);
struct _SdxMathTweenAccessor {
	gint ref_count;
	SdxMathTweenAccessorGetValues GetValues;
	gpointer GetValues_target;
	GDestroyNotify GetValues_target_destroy_notify;
	SdxMathTweenAccessorSetValues SetValues;
	gpointer SetValues_target;
	GDestroyNotify SetValues_target_destroy_notify;
};



void sdx_math_tween_accessor_free (SdxMathTweenAccessor * self);
static void sdx_math_tween_accessor_instance_init (SdxMathTweenAccessor * self);
static gint _sdx_math_tween_accessor_get_values_lambda73_ (void* target, gint type, gfloat** values, int* values_length1);
static gint __sdx_math_tween_accessor_get_values_lambda73__sdx_math_tween_accessor_get_values (void* target, gint tweenType, gfloat** returnValues, int* returnValues_length1, gpointer self);
static void _sdx_math_tween_accessor_set_values_lambda74_ (void* target, gint type, gfloat** values, int* values_length1);
static void __sdx_math_tween_accessor_set_values_lambda74__sdx_math_tween_accessor_set_values (void* target, gint tweenType, gfloat** newValues, int* newValues_length1, gpointer self);
SdxMathTweenAccessor* sdx_math_tween_accessor_retain (SdxMathTweenAccessor* self);
void sdx_math_tween_accessor_release (SdxMathTweenAccessor* self);
void sdx_math_tween_accessor_free (SdxMathTweenAccessor* self);
SdxMathTweenAccessor* sdx_math_tween_accessor_new (void);


static gint _sdx_math_tween_accessor_get_values_lambda73_ (void* target, gint type, gfloat** values, int* values_length1) {
	gint result = 0;
	result = 0;
	return result;
}


static gint __sdx_math_tween_accessor_get_values_lambda73__sdx_math_tween_accessor_get_values (void* target, gint tweenType, gfloat** returnValues, int* returnValues_length1, gpointer self) {
	gint result;
	result = _sdx_math_tween_accessor_get_values_lambda73_ (target, tweenType, returnValues, returnValues_length1);
	return result;
}


static void _sdx_math_tween_accessor_set_values_lambda74_ (void* target, gint type, gfloat** values, int* values_length1) {
}


static void __sdx_math_tween_accessor_set_values_lambda74__sdx_math_tween_accessor_set_values (void* target, gint tweenType, gfloat** newValues, int* newValues_length1, gpointer self) {
	_sdx_math_tween_accessor_set_values_lambda74_ (target, tweenType, newValues, newValues_length1);
}


SdxMathTweenAccessor* sdx_math_tween_accessor_retain (SdxMathTweenAccessor* self) {
	SdxMathTweenAccessor* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->ref_count), 1);
	result = self;
	return result;
}


void sdx_math_tween_accessor_release (SdxMathTweenAccessor* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->ref_count));
	if (_tmp0_) {
		sdx_math_tween_accessor_free (self);
	}
}


SdxMathTweenAccessor* sdx_math_tween_accessor_new (void) {
	SdxMathTweenAccessor* self;
	self = g_slice_new0 (SdxMathTweenAccessor);
	sdx_math_tween_accessor_instance_init (self);
	return self;
}


static void sdx_math_tween_accessor_instance_init (SdxMathTweenAccessor * self) {
	self->ref_count = 1;
	self->GetValues = __sdx_math_tween_accessor_get_values_lambda73__sdx_math_tween_accessor_get_values;
	self->GetValues_target = self;
	self->GetValues_target_destroy_notify = NULL;
	self->SetValues = __sdx_math_tween_accessor_set_values_lambda74__sdx_math_tween_accessor_set_values;
	self->SetValues_target = self;
	self->SetValues_target_destroy_notify = NULL;
}


void sdx_math_tween_accessor_free (SdxMathTweenAccessor * self) {
	(self->GetValues_target_destroy_notify == NULL) ? NULL : (self->GetValues_target_destroy_notify (self->GetValues_target), NULL);
	self->GetValues = NULL;
	self->GetValues_target = NULL;
	self->GetValues_target_destroy_notify = NULL;
	(self->SetValues_target_destroy_notify == NULL) ? NULL : (self->SetValues_target_destroy_notify (self->SetValues_target), NULL);
	self->SetValues = NULL;
	self->SetValues_target = NULL;
	self->SetValues_target_destroy_notify = NULL;
	g_slice_free (SdxMathTweenAccessor, self);
}




