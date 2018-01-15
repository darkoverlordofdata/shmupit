/** updated by adriac */
/* Matcher.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from Matcher.vala, do not modify */

/*[Adriac:Entitas::Matcher:EntitasMatcher:entitas_matcher]*/
/* ******************************************************************************
 *# MIT License
 *
 * Copyright (c) 2015-2017 Bruce Davidson &lt;darkoverlordofdata@gmail.com&gt;
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <SDL_rect.h>

typedef struct _EntitasMatcher EntitasMatcher;
#define _g_free0(var) (var = (g_free (var), NULL))

#define ENTITAS_TYPE_ENTITY (entitas_entity_get_type ())

#define ENTITAS_TYPE_TRANSFORM (entitas_transform_get_type ())

#define SDX_MATH_TYPE_VECTOR2 (sdx_math_vector2_get_type ())
typedef struct _SdxMathVector2 SdxMathVector2;
typedef struct _SdxGraphicsSprite SdxGraphicsSprite;
typedef struct _EntitasTransform EntitasTransform;
typedef struct _EntitasEventEntityChanged EntitasEventEntityChanged;
typedef struct _EntitasEventEntityReleased EntitasEventEntityReleased;
typedef struct _EntitasEventComponentReplaced EntitasEventComponentReplaced;

#define ENTITAS_TYPE_BACKGROUND (entitas_background_get_type ())
typedef struct _EntitasBackground EntitasBackground;

#define ENTITAS_TYPE_BULLET (entitas_bullet_get_type ())
typedef struct _EntitasBullet EntitasBullet;

#define ENTITAS_TYPE_ENEMY1 (entitas_enemy1_get_type ())
typedef struct _EntitasEnemy1 EntitasEnemy1;

#define ENTITAS_TYPE_ENEMY2 (entitas_enemy2_get_type ())
typedef struct _EntitasEnemy2 EntitasEnemy2;

#define ENTITAS_TYPE_ENEMY3 (entitas_enemy3_get_type ())
typedef struct _EntitasEnemy3 EntitasEnemy3;

#define ENTITAS_TYPE_EXPIRES (entitas_expires_get_type ())
typedef struct _EntitasExpires EntitasExpires;

#define ENTITAS_TYPE_HEALTH (entitas_health_get_type ())
typedef struct _EntitasHealth EntitasHealth;

#define ENTITAS_TYPE_HUD (entitas_hud_get_type ())
typedef struct _EntitasHud EntitasHud;

#define ENTITAS_TYPE_LAYER (entitas_layer_get_type ())
typedef struct _EntitasLayer EntitasLayer;

#define ENTITAS_TYPE_PLAYER (entitas_player_get_type ())
typedef struct _EntitasPlayer EntitasPlayer;

#define ENTITAS_TYPE_SHOW (entitas_show_get_type ())
typedef struct _EntitasShow EntitasShow;

#define ENTITAS_TYPE_SOUND (entitas_sound_get_type ())
typedef struct _SdxAudioSound SdxAudioSound;
typedef struct _EntitasSound EntitasSound;

#define ENTITAS_TYPE_TEXT (entitas_text_get_type ())
typedef SdxGraphicsSprite SdxGraphicsSpriteTextSprite;
typedef struct _EntitasText EntitasText;

#define ENTITAS_TYPE_TINT (entitas_tint_get_type ())
typedef struct _EntitasTint EntitasTint;

#define ENTITAS_TYPE_TWEEN (entitas_tween_get_type ())
typedef struct _EntitasTween EntitasTween;

#define ENTITAS_TYPE_VELOCITY (entitas_velocity_get_type ())
typedef struct _EntitasVelocity EntitasVelocity;
typedef struct _EntitasEntity EntitasEntity;
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
// symtbl.1 entitas_matcher
void entitas_matcher_release (EntitasMatcher* self);
void entitas_matcher_free (EntitasMatcher* self);
EntitasMatcher* entitas_matcher_retain (EntitasMatcher* self);
#define _entitas_matcher_release0(var) ((var == NULL) ? NULL : (var = (entitas_matcher_release (var), NULL)))

struct _EntitasMatcher {
	gint ref_count;
	gint id;
	gint* allOfIndices;
	gint allOfIndices_length1;
	guint64 allOfMask;
	gint* anyOfIndices;
	gint anyOfIndices_length1;
	guint64 anyOfMask;
	gint* noneOfIndices;
	gint noneOfIndices_length1;
	guint64 noneOfMask;
	gint* indices;
	gint indices_length1;
	gchar* toStringCache;
};

struct _SdxMathVector2 {
	gfloat x;
	gfloat y;
};

struct _EntitasTransform {
	SdxMathVector2* scale;
	SdxMathVector2* position;
	SDL_Rect* aabb;
	SdxGraphicsSprite* sprite;
};

struct _EntitasBackground {
	gboolean active;
};

struct _EntitasBullet {
	gboolean active;
};

struct _EntitasEnemy1 {
	gboolean active;
};

struct _EntitasEnemy2 {
	gboolean active;
};

struct _EntitasEnemy3 {
	gboolean active;
};

struct _EntitasExpires {
	gfloat value;
};

struct _EntitasHealth {
	gfloat current;
	gfloat maximum;
};

struct _EntitasHud {
	gboolean active;
};

struct _EntitasLayer {
	gint value;
};

struct _EntitasPlayer {
	gboolean active;
};

struct _EntitasShow {
	gboolean active;
};

struct _EntitasSound {
	SdxAudioSound* sound;
};

struct _EntitasText {
	gchar* text;
	SdxGraphicsSpriteTextSprite* sprite;
};

struct _EntitasTint {
	gint r;
	gint g;
	gint b;
	gint a;
};

struct _EntitasTween {
	gfloat min;
	gfloat max;
	gfloat speed;
	gboolean repeat;
	gboolean active;
};

struct _EntitasVelocity {
	gfloat x;
	gfloat y;
};

struct _EntitasEntity {
	gint id;
	gchar* name;
	gint pool;
	guint64 mask;
	EntitasTransform transform;
	EntitasEventEntityChanged* onComponentAdded;
	EntitasEventEntityChanged* onComponentRemoved;
	EntitasEventEntityReleased* onEntityReleased;
	EntitasEventComponentReplaced* onComponentReplaced;
	EntitasBackground* background;
	EntitasBullet* bullet;
	EntitasEnemy1* enemy1;
	EntitasEnemy2* enemy2;
	EntitasEnemy3* enemy3;
	EntitasExpires* expires;
	EntitasHealth* health;
	EntitasHud* hud;
	EntitasLayer* layer;
	EntitasPlayer* player;
	EntitasShow* show;
	EntitasSound* sound;
	EntitasText* text;
	EntitasTint* tint;
	EntitasTween* tween;
	EntitasVelocity* velocity;
};


extern gint entitas_matcher_uniqueId;
gint entitas_matcher_uniqueId = 0;

void entitas_matcher_free (EntitasMatcher * self);
static void entitas_matcher_instance_init (EntitasMatcher * self);
EntitasMatcher* entitas_matcher_retain (EntitasMatcher* self);
void entitas_matcher_release (EntitasMatcher* self);
void entitas_matcher_free (EntitasMatcher* self);
EntitasMatcher* entitas_matcher_new (EntitasMatcher** matchers, int matchers_length1);
static void _vala_array_add1 (gint* * array, int* length, int* size, gint value);
static void _vala_array_add2 (gint* * array, int* length, int* size, gint value);
static void _vala_array_add3 (gint* * array, int* length, int* size, gint value);
gint* entitas_matcher_DistinctIndices (gint* indices, int indices_length1, int* result_length1);
GType entitas_entity_get_type (void) G_GNUC_CONST;
GType entitas_transform_get_type (void) G_GNUC_CONST;
GType sdx_math_vector2_get_type (void) G_GNUC_CONST;
SdxMathVector2* sdx_math_vector2_dup (const SdxMathVector2* self);
void sdx_math_vector2_free (SdxMathVector2* self);
void sdx_graphics_sprite_free (SdxGraphicsSprite * self);
EntitasTransform* entitas_transform_dup (const EntitasTransform* self);
void entitas_transform_free (EntitasTransform* self);
void entitas_transform_copy (const EntitasTransform* self, EntitasTransform* dest);
void entitas_transform_destroy (EntitasTransform* self);
void entitas_event_entity_changed_free (EntitasEventEntityChanged * self);
void entitas_event_entity_released_free (EntitasEventEntityReleased * self);
void entitas_event_component_replaced_free (EntitasEventComponentReplaced * self);
GType entitas_background_get_type (void) G_GNUC_CONST;
EntitasBackground* entitas_background_dup (const EntitasBackground* self);
void entitas_background_free (EntitasBackground* self);
GType entitas_bullet_get_type (void) G_GNUC_CONST;
EntitasBullet* entitas_bullet_dup (const EntitasBullet* self);
void entitas_bullet_free (EntitasBullet* self);
GType entitas_enemy1_get_type (void) G_GNUC_CONST;
EntitasEnemy1* entitas_enemy1_dup (const EntitasEnemy1* self);
void entitas_enemy1_free (EntitasEnemy1* self);
GType entitas_enemy2_get_type (void) G_GNUC_CONST;
EntitasEnemy2* entitas_enemy2_dup (const EntitasEnemy2* self);
void entitas_enemy2_free (EntitasEnemy2* self);
GType entitas_enemy3_get_type (void) G_GNUC_CONST;
EntitasEnemy3* entitas_enemy3_dup (const EntitasEnemy3* self);
void entitas_enemy3_free (EntitasEnemy3* self);
GType entitas_expires_get_type (void) G_GNUC_CONST;
EntitasExpires* entitas_expires_dup (const EntitasExpires* self);
void entitas_expires_free (EntitasExpires* self);
GType entitas_health_get_type (void) G_GNUC_CONST;
EntitasHealth* entitas_health_dup (const EntitasHealth* self);
void entitas_health_free (EntitasHealth* self);
GType entitas_hud_get_type (void) G_GNUC_CONST;
EntitasHud* entitas_hud_dup (const EntitasHud* self);
void entitas_hud_free (EntitasHud* self);
GType entitas_layer_get_type (void) G_GNUC_CONST;
EntitasLayer* entitas_layer_dup (const EntitasLayer* self);
void entitas_layer_free (EntitasLayer* self);
GType entitas_player_get_type (void) G_GNUC_CONST;
EntitasPlayer* entitas_player_dup (const EntitasPlayer* self);
void entitas_player_free (EntitasPlayer* self);
GType entitas_show_get_type (void) G_GNUC_CONST;
EntitasShow* entitas_show_dup (const EntitasShow* self);
void entitas_show_free (EntitasShow* self);
GType entitas_sound_get_type (void) G_GNUC_CONST;
void sdx_audio_sound_free (SdxAudioSound * self);
EntitasSound* entitas_sound_dup (const EntitasSound* self);
void entitas_sound_free (EntitasSound* self);
void entitas_sound_copy (const EntitasSound* self, EntitasSound* dest);
void entitas_sound_destroy (EntitasSound* self);
GType entitas_text_get_type (void) G_GNUC_CONST;
EntitasText* entitas_text_dup (const EntitasText* self);
void entitas_text_free (EntitasText* self);
void entitas_text_copy (const EntitasText* self, EntitasText* dest);
void entitas_text_destroy (EntitasText* self);
GType entitas_tint_get_type (void) G_GNUC_CONST;
EntitasTint* entitas_tint_dup (const EntitasTint* self);
void entitas_tint_free (EntitasTint* self);
GType entitas_tween_get_type (void) G_GNUC_CONST;
EntitasTween* entitas_tween_dup (const EntitasTween* self);
void entitas_tween_free (EntitasTween* self);
GType entitas_velocity_get_type (void) G_GNUC_CONST;
EntitasVelocity* entitas_velocity_dup (const EntitasVelocity* self);
void entitas_velocity_free (EntitasVelocity* self);
EntitasEntity* entitas_entity_dup (const EntitasEntity* self);
void entitas_entity_free (EntitasEntity* self);
void entitas_entity_copy (const EntitasEntity* self, EntitasEntity* dest);
void entitas_entity_destroy (EntitasEntity* self);
gboolean entitas_matcher_Matches (EntitasMatcher* self, EntitasEntity* entity);
#define ENTITAS_ACTIVE ((guint64) 0x8000000000000000LL)
gint* entitas_matcher_MergeIndices (EntitasMatcher* self, int* result_length1);
static void _vala_array_add4 (gint* * array, int* length, int* size, gint value);
static void _vala_array_add5 (gint* * array, int* length, int* size, gint value);
static void _vala_array_add6 (gint* * array, int* length, int* size, gint value);
gchar* entitas_matcher_ToString (EntitasMatcher* self);
gchar* entitas_matcher_ComponentsToString (gint* indexArray, int indexArray_length1);
gint* entitas_matcher_ListToArray (GList* list, int* result_length1);
EntitasMatcher* entitas_matcher_NoneOf (gint* components, int components_length1);
guint64 entitas_matcher_BuildMask (gint* indices, int indices_length1);
EntitasMatcher* entitas_matcher_AllOf (gint* components, int components_length1);
EntitasMatcher* entitas_matcher_AnyOf (gint* components, int components_length1);

extern const gchar* ENTITAS_ComponentString[17];
extern const guint64 ENTITAS_POW2[65];

EntitasMatcher* entitas_matcher_retain (EntitasMatcher* self) {
	EntitasMatcher* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->ref_count), 1);
	result = self;
	return result;
}


void entitas_matcher_release (EntitasMatcher* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->ref_count));
	if (_tmp0_) {
		entitas_matcher_free (self);
	}
}


/**
 *  clone/merge 1 or more existing matchers
 */
static void _vala_array_add1 (gint* * array, int* length, int* size, gint value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gint, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void _vala_array_add2 (gint* * array, int* length, int* size, gint value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gint, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void _vala_array_add3 (gint* * array, int* length, int* size, gint value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gint, *array, *size);
	}
	(*array)[(*length)++] = value;
}


EntitasMatcher* entitas_matcher_new (EntitasMatcher** matchers, int matchers_length1) {
	EntitasMatcher* self;
	gint _tmp0_;
	EntitasMatcher** _tmp1_;
	gint _tmp1__length1;
	self = g_slice_new0 (EntitasMatcher);
	entitas_matcher_instance_init (self);
	_tmp0_ = entitas_matcher_uniqueId;
	entitas_matcher_uniqueId = _tmp0_ + 1;
	self->id = _tmp0_;
	_tmp1_ = matchers;
	_tmp1__length1 = matchers_length1;
	if (_tmp1_ != NULL) {
		gint* allOf = NULL;
		gint* _tmp2_;
		gint allOf_length1;
		gint _allOf_size_;
		gint* anyOf = NULL;
		gint* _tmp3_;
		gint anyOf_length1;
		gint _anyOf_size_;
		gint* noneOf = NULL;
		gint* _tmp4_;
		gint noneOf_length1;
		gint _noneOf_size_;
		gint* _tmp42_;
		gint _tmp42__length1;
		gint _tmp43_;
		gint* _tmp44_;
		gint* _tmp45_;
		gint _tmp45__length1;
		gint _tmp46_;
		gint* _tmp47_;
		gint* _tmp48_;
		gint _tmp48__length1;
		gint _tmp49_;
		gint* _tmp50_;
		_tmp2_ = g_new0 (gint, 0);
		allOf = _tmp2_;
		allOf_length1 = 0;
		_allOf_size_ = allOf_length1;
		_tmp3_ = g_new0 (gint, 0);
		anyOf = _tmp3_;
		anyOf_length1 = 0;
		_anyOf_size_ = anyOf_length1;
		_tmp4_ = g_new0 (gint, 0);
		noneOf = _tmp4_;
		noneOf_length1 = 0;
		_noneOf_size_ = noneOf_length1;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp5_ = FALSE;
				_tmp5_ = TRUE;
				while (TRUE) {
					gint _tmp7_;
					EntitasMatcher** _tmp8_;
					gint _tmp8__length1;
					guint64 _tmp9_;
					EntitasMatcher** _tmp10_;
					gint _tmp10__length1;
					gint _tmp11_;
					EntitasMatcher* _tmp12_;
					guint64 _tmp13_;
					guint64 _tmp14_;
					EntitasMatcher** _tmp15_;
					gint _tmp15__length1;
					gint _tmp16_;
					EntitasMatcher* _tmp17_;
					guint64 _tmp18_;
					guint64 _tmp19_;
					EntitasMatcher** _tmp20_;
					gint _tmp20__length1;
					gint _tmp21_;
					EntitasMatcher* _tmp22_;
					guint64 _tmp23_;
					EntitasMatcher** _tmp24_;
					gint _tmp24__length1;
					gint _tmp25_;
					EntitasMatcher* _tmp26_;
					gint* _tmp27_;
					gint _tmp27__length1;
					EntitasMatcher** _tmp30_;
					gint _tmp30__length1;
					gint _tmp31_;
					EntitasMatcher* _tmp32_;
					gint* _tmp33_;
					gint _tmp33__length1;
					EntitasMatcher** _tmp36_;
					gint _tmp36__length1;
					gint _tmp37_;
					EntitasMatcher* _tmp38_;
					gint* _tmp39_;
					gint _tmp39__length1;
					if (!_tmp5_) {
						gint _tmp6_;
						_tmp6_ = i;
						i = _tmp6_ + 1;
					}
					_tmp5_ = FALSE;
					_tmp7_ = i;
					_tmp8_ = matchers;
					_tmp8__length1 = matchers_length1;
					if (!(_tmp7_ < _tmp8__length1)) {
						break;
					}
					_tmp9_ = self->allOfMask;
					_tmp10_ = matchers;
					_tmp10__length1 = matchers_length1;
					_tmp11_ = i;
					_tmp12_ = _tmp10_[_tmp11_];
					_tmp13_ = _tmp12_->allOfMask;
					self->allOfMask = _tmp9_ | _tmp13_;
					_tmp14_ = self->anyOfMask;
					_tmp15_ = matchers;
					_tmp15__length1 = matchers_length1;
					_tmp16_ = i;
					_tmp17_ = _tmp15_[_tmp16_];
					_tmp18_ = _tmp17_->anyOfMask;
					self->anyOfMask = _tmp14_ | _tmp18_;
					_tmp19_ = self->noneOfMask;
					_tmp20_ = matchers;
					_tmp20__length1 = matchers_length1;
					_tmp21_ = i;
					_tmp22_ = _tmp20_[_tmp21_];
					_tmp23_ = _tmp22_->noneOfMask;
					self->noneOfMask = _tmp19_ | _tmp23_;
					_tmp24_ = matchers;
					_tmp24__length1 = matchers_length1;
					_tmp25_ = i;
					_tmp26_ = _tmp24_[_tmp25_];
					_tmp27_ = _tmp26_->allOfIndices;
					_tmp27__length1 = _tmp26_->allOfIndices_length1;
					{
						gint* j_collection = NULL;
						gint j_collection_length1 = 0;
						gint _j_collection_size_ = 0;
						gint j_it = 0;
						j_collection = _tmp27_;
						j_collection_length1 = _tmp27__length1;
						for (j_it = 0; j_it < _tmp27__length1; j_it = j_it + 1) {
							gint j = 0;
							j = j_collection[j_it];
							{
								gint* _tmp28_;
								gint _tmp28__length1;
								gint _tmp29_;
								_tmp28_ = allOf;
								_tmp28__length1 = allOf_length1;
								_tmp29_ = j;
								_vala_array_add1 (&allOf, &allOf_length1, &_allOf_size_, _tmp29_);
							}
						}
					}
					_tmp30_ = matchers;
					_tmp30__length1 = matchers_length1;
					_tmp31_ = i;
					_tmp32_ = _tmp30_[_tmp31_];
					_tmp33_ = _tmp32_->anyOfIndices;
					_tmp33__length1 = _tmp32_->anyOfIndices_length1;
					{
						gint* j_collection = NULL;
						gint j_collection_length1 = 0;
						gint _j_collection_size_ = 0;
						gint j_it = 0;
						j_collection = _tmp33_;
						j_collection_length1 = _tmp33__length1;
						for (j_it = 0; j_it < _tmp33__length1; j_it = j_it + 1) {
							gint j = 0;
							j = j_collection[j_it];
							{
								gint* _tmp34_;
								gint _tmp34__length1;
								gint _tmp35_;
								_tmp34_ = anyOf;
								_tmp34__length1 = anyOf_length1;
								_tmp35_ = j;
								_vala_array_add2 (&anyOf, &anyOf_length1, &_anyOf_size_, _tmp35_);
							}
						}
					}
					_tmp36_ = matchers;
					_tmp36__length1 = matchers_length1;
					_tmp37_ = i;
					_tmp38_ = _tmp36_[_tmp37_];
					_tmp39_ = _tmp38_->noneOfIndices;
					_tmp39__length1 = _tmp38_->noneOfIndices_length1;
					{
						gint* j_collection = NULL;
						gint j_collection_length1 = 0;
						gint _j_collection_size_ = 0;
						gint j_it = 0;
						j_collection = _tmp39_;
						j_collection_length1 = _tmp39__length1;
						for (j_it = 0; j_it < _tmp39__length1; j_it = j_it + 1) {
							gint j = 0;
							j = j_collection[j_it];
							{
								gint* _tmp40_;
								gint _tmp40__length1;
								gint _tmp41_;
								_tmp40_ = noneOf;
								_tmp40__length1 = noneOf_length1;
								_tmp41_ = j;
								_vala_array_add3 (&noneOf, &noneOf_length1, &_noneOf_size_, _tmp41_);
							}
						}
					}
				}
			}
		}
		_tmp42_ = allOf;
		_tmp42__length1 = allOf_length1;
		_tmp44_ = entitas_matcher_DistinctIndices (_tmp42_, _tmp42__length1, &_tmp43_);
		self->allOfIndices = (g_free (self->allOfIndices), NULL);
		self->allOfIndices = _tmp44_;
		self->allOfIndices_length1 = _tmp43_;
		_tmp45_ = anyOf;
		_tmp45__length1 = anyOf_length1;
		_tmp47_ = entitas_matcher_DistinctIndices (_tmp45_, _tmp45__length1, &_tmp46_);
		self->anyOfIndices = (g_free (self->anyOfIndices), NULL);
		self->anyOfIndices = _tmp47_;
		self->anyOfIndices_length1 = _tmp46_;
		_tmp48_ = noneOf;
		_tmp48__length1 = noneOf_length1;
		_tmp50_ = entitas_matcher_DistinctIndices (_tmp48_, _tmp48__length1, &_tmp49_);
		self->noneOfIndices = (g_free (self->noneOfIndices), NULL);
		self->noneOfIndices = _tmp50_;
		self->noneOfIndices_length1 = _tmp49_;
		noneOf = (g_free (noneOf), NULL);
		anyOf = (g_free (anyOf), NULL);
		allOf = (g_free (allOf), NULL);
	}
	return self;
}


/**
 * Check if the entity matches this matcher
 * @param entity to match 
 * @return boolean true if matches else false
 */
gboolean entitas_matcher_Matches (EntitasMatcher* self, EntitasEntity* entity) {
	gboolean result = FALSE;
	guint64 mask = 0ULL;
	EntitasEntity* _tmp0_;
	guint64 _tmp1_;
	gboolean _tmp2_ = FALSE;
	guint64 _tmp3_;
	gboolean matchesAllOf = FALSE;
	gboolean _tmp7_ = FALSE;
	guint64 _tmp8_;
	gboolean matchesAnyOf = FALSE;
	gboolean _tmp11_ = FALSE;
	guint64 _tmp12_;
	gboolean matchesNoneOf = FALSE;
	gboolean _tmp15_ = FALSE;
	gboolean _tmp16_ = FALSE;
	gboolean _tmp17_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = entity;
	_tmp1_ = (*_tmp0_).mask;
	mask = _tmp1_ ^ ENTITAS_ACTIVE;
	_tmp3_ = self->allOfMask;
	if (_tmp3_ == ((guint64) 0)) {
		_tmp2_ = TRUE;
	} else {
		guint64 _tmp4_;
		guint64 _tmp5_;
		guint64 _tmp6_;
		_tmp4_ = mask;
		_tmp5_ = self->allOfMask;
		_tmp6_ = self->allOfMask;
		_tmp2_ = (_tmp4_ & _tmp5_) == _tmp6_;
	}
	matchesAllOf = _tmp2_;
	_tmp8_ = self->anyOfMask;
	if (_tmp8_ == ((guint64) 0)) {
		_tmp7_ = TRUE;
	} else {
		guint64 _tmp9_;
		guint64 _tmp10_;
		_tmp9_ = mask;
		_tmp10_ = self->anyOfMask;
		_tmp7_ = (_tmp9_ & _tmp10_) != ((guint64) 0);
	}
	matchesAnyOf = _tmp7_;
	_tmp12_ = self->noneOfMask;
	if (_tmp12_ == ((guint64) 0)) {
		_tmp11_ = TRUE;
	} else {
		guint64 _tmp13_;
		guint64 _tmp14_;
		_tmp13_ = mask;
		_tmp14_ = self->noneOfMask;
		_tmp11_ = (_tmp13_ & _tmp14_) == ((guint64) 0);
	}
	matchesNoneOf = _tmp11_;
	_tmp17_ = matchesAllOf;
	if (_tmp17_) {
		gboolean _tmp18_;
		_tmp18_ = matchesAnyOf;
		_tmp16_ = _tmp18_;
	} else {
		_tmp16_ = FALSE;
	}
	if (_tmp16_) {
		gboolean _tmp19_;
		_tmp19_ = matchesNoneOf;
		_tmp15_ = _tmp19_;
	} else {
		_tmp15_ = FALSE;
	}
	result = _tmp15_;
	return result;
}


/**
 * Merge list of component indices
 * @return Array<number>
 */
static void _vala_array_add4 (gint* * array, int* length, int* size, gint value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gint, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void _vala_array_add5 (gint* * array, int* length, int* size, gint value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gint, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void _vala_array_add6 (gint* * array, int* length, int* size, gint value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gint, *array, *size);
	}
	(*array)[(*length)++] = value;
}


gint* entitas_matcher_MergeIndices (EntitasMatcher* self, int* result_length1) {
	gint* result = NULL;
	gint* indices = NULL;
	gint* _tmp0_;
	gint indices_length1;
	gint _indices_size_;
	gint* _tmp1_;
	gint _tmp1__length1;
	gint* _tmp5_;
	gint _tmp5__length1;
	gint* _tmp9_;
	gint _tmp9__length1;
	gint* _tmp13_;
	gint _tmp13__length1;
	gint _tmp14_;
	gint* _tmp15_;
	gint* _tmp16_;
	gint _tmp16__length1;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_new0 (gint, 0);
	indices = _tmp0_;
	indices_length1 = 0;
	_indices_size_ = indices_length1;
	_tmp1_ = self->allOfIndices;
	_tmp1__length1 = self->allOfIndices_length1;
	if (_tmp1_ != NULL) {
		gint* _tmp2_;
		gint _tmp2__length1;
		_tmp2_ = self->allOfIndices;
		_tmp2__length1 = self->allOfIndices_length1;
		{
			gint* i_collection = NULL;
			gint i_collection_length1 = 0;
			gint _i_collection_size_ = 0;
			gint i_it = 0;
			i_collection = _tmp2_;
			i_collection_length1 = _tmp2__length1;
			for (i_it = 0; i_it < _tmp2__length1; i_it = i_it + 1) {
				gint i = 0;
				i = i_collection[i_it];
				{
					gint* _tmp3_;
					gint _tmp3__length1;
					gint _tmp4_;
					_tmp3_ = indices;
					_tmp3__length1 = indices_length1;
					_tmp4_ = i;
					_vala_array_add4 (&indices, &indices_length1, &_indices_size_, _tmp4_);
				}
			}
		}
	}
	_tmp5_ = self->anyOfIndices;
	_tmp5__length1 = self->anyOfIndices_length1;
	if (_tmp5_ != NULL) {
		gint* _tmp6_;
		gint _tmp6__length1;
		_tmp6_ = self->anyOfIndices;
		_tmp6__length1 = self->anyOfIndices_length1;
		{
			gint* i_collection = NULL;
			gint i_collection_length1 = 0;
			gint _i_collection_size_ = 0;
			gint i_it = 0;
			i_collection = _tmp6_;
			i_collection_length1 = _tmp6__length1;
			for (i_it = 0; i_it < _tmp6__length1; i_it = i_it + 1) {
				gint i = 0;
				i = i_collection[i_it];
				{
					gint* _tmp7_;
					gint _tmp7__length1;
					gint _tmp8_;
					_tmp7_ = indices;
					_tmp7__length1 = indices_length1;
					_tmp8_ = i;
					_vala_array_add5 (&indices, &indices_length1, &_indices_size_, _tmp8_);
				}
			}
		}
	}
	_tmp9_ = self->noneOfIndices;
	_tmp9__length1 = self->noneOfIndices_length1;
	if (_tmp9_ != NULL) {
		gint* _tmp10_;
		gint _tmp10__length1;
		_tmp10_ = self->noneOfIndices;
		_tmp10__length1 = self->noneOfIndices_length1;
		{
			gint* i_collection = NULL;
			gint i_collection_length1 = 0;
			gint _i_collection_size_ = 0;
			gint i_it = 0;
			i_collection = _tmp10_;
			i_collection_length1 = _tmp10__length1;
			for (i_it = 0; i_it < _tmp10__length1; i_it = i_it + 1) {
				gint i = 0;
				i = i_collection[i_it];
				{
					gint* _tmp11_;
					gint _tmp11__length1;
					gint _tmp12_;
					_tmp11_ = indices;
					_tmp11__length1 = indices_length1;
					_tmp12_ = i;
					_vala_array_add6 (&indices, &indices_length1, &_indices_size_, _tmp12_);
				}
			}
		}
	}
	_tmp13_ = indices;
	_tmp13__length1 = indices_length1;
	_tmp15_ = entitas_matcher_DistinctIndices (_tmp13_, _tmp13__length1, &_tmp14_);
	_tmp16_ = _tmp15_;
	_tmp16__length1 = _tmp14_;
	if (result_length1) {
		*result_length1 = _tmp16__length1;
	}
	result = _tmp16_;
	indices = (g_free (indices), NULL);
	return result;
}


/**
 * toString representation of this matcher
 * @return string
 */
gchar* entitas_matcher_ToString (EntitasMatcher* self) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp28_;
	gchar* _tmp29_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->toStringCache;
	if (_tmp0_ == NULL) {
		GString* sb = NULL;
		GString* _tmp1_;
		gint* _tmp2_;
		gint _tmp2__length1;
		gint* _tmp9_;
		gint _tmp9__length1;
		gint* _tmp18_;
		gint _tmp18__length1;
		GString* _tmp25_;
		const gchar* _tmp26_;
		gchar* _tmp27_;
		_tmp1_ = g_string_new ("");
		sb = _tmp1_;
		_tmp2_ = self->allOfIndices;
		_tmp2__length1 = self->allOfIndices_length1;
		if (_tmp2_ != NULL) {
			GString* _tmp3_;
			GString* _tmp4_;
			gint* _tmp5_;
			gint _tmp5__length1;
			gchar* _tmp6_;
			gchar* _tmp7_;
			GString* _tmp8_;
			_tmp3_ = sb;
			_tmp4_ = g_string_append (_tmp3_, "AllOf(");
			_tmp5_ = self->allOfIndices;
			_tmp5__length1 = self->allOfIndices_length1;
			_tmp6_ = entitas_matcher_ComponentsToString (_tmp5_, _tmp5__length1);
			_tmp7_ = _tmp6_;
			_tmp8_ = g_string_append (_tmp4_, _tmp7_);
			g_string_append (_tmp8_, ")");
			_g_free0 (_tmp7_);
		}
		_tmp9_ = self->anyOfIndices;
		_tmp9__length1 = self->anyOfIndices_length1;
		if (_tmp9_ != NULL) {
			gint* _tmp10_;
			gint _tmp10__length1;
			GString* _tmp12_;
			GString* _tmp13_;
			gint* _tmp14_;
			gint _tmp14__length1;
			gchar* _tmp15_;
			gchar* _tmp16_;
			GString* _tmp17_;
			_tmp10_ = self->allOfIndices;
			_tmp10__length1 = self->allOfIndices_length1;
			if (_tmp10_ != NULL) {
				GString* _tmp11_;
				_tmp11_ = sb;
				g_string_append (_tmp11_, ".");
			}
			_tmp12_ = sb;
			_tmp13_ = g_string_append (_tmp12_, "AnyOf(");
			_tmp14_ = self->anyOfIndices;
			_tmp14__length1 = self->anyOfIndices_length1;
			_tmp15_ = entitas_matcher_ComponentsToString (_tmp14_, _tmp14__length1);
			_tmp16_ = _tmp15_;
			_tmp17_ = g_string_append (_tmp13_, _tmp16_);
			g_string_append (_tmp17_, ")");
			_g_free0 (_tmp16_);
		}
		_tmp18_ = self->noneOfIndices;
		_tmp18__length1 = self->noneOfIndices_length1;
		if (_tmp18_ != NULL) {
			GString* _tmp19_;
			GString* _tmp20_;
			gint* _tmp21_;
			gint _tmp21__length1;
			gchar* _tmp22_;
			gchar* _tmp23_;
			GString* _tmp24_;
			_tmp19_ = sb;
			_tmp20_ = g_string_append (_tmp19_, ".NoneOf(");
			_tmp21_ = self->noneOfIndices;
			_tmp21__length1 = self->noneOfIndices_length1;
			_tmp22_ = entitas_matcher_ComponentsToString (_tmp21_, _tmp21__length1);
			_tmp23_ = _tmp22_;
			_tmp24_ = g_string_append (_tmp20_, _tmp23_);
			g_string_append (_tmp24_, ")");
			_g_free0 (_tmp23_);
		}
		_tmp25_ = sb;
		_tmp26_ = _tmp25_->str;
		_tmp27_ = g_strdup (_tmp26_);
		_g_free0 (self->toStringCache);
		self->toStringCache = _tmp27_;
		_g_string_free0 (sb);
	}
	_tmp28_ = self->toStringCache;
	_tmp29_ = g_strdup (_tmp28_);
	result = _tmp29_;
	return result;
}


gchar* entitas_matcher_ComponentsToString (gint* indexArray, int indexArray_length1) {
	gchar* result = NULL;
	GString* sb = NULL;
	GString* _tmp0_;
	gint i = 0;
	gint* _tmp1_;
	gint _tmp1__length1;
	GString* _tmp6_;
	GString* _tmp7_;
	gssize _tmp8_;
	gint _tmp9_;
	GString* _tmp10_;
	const gchar* _tmp11_;
	gchar* _tmp12_;
	_tmp0_ = g_string_new ("");
	sb = _tmp0_;
	i = 0;
	_tmp1_ = indexArray;
	_tmp1__length1 = indexArray_length1;
	{
		gint* index_collection = NULL;
		gint index_collection_length1 = 0;
		gint _index_collection_size_ = 0;
		gint index_it = 0;
		index_collection = _tmp1_;
		index_collection_length1 = _tmp1__length1;
		for (index_it = 0; index_it < _tmp1__length1; index_it = index_it + 1) {
			gint index = 0;
			index = index_collection[index_it];
			{
				GString* _tmp2_;
				gint _tmp3_;
				const gchar* _tmp4_;
				GString* _tmp5_;
				_tmp2_ = sb;
				_tmp3_ = index;
				_tmp4_ = ENTITAS_ComponentString[_tmp3_];
				_tmp5_ = g_string_append (_tmp2_, _tmp4_);
				g_string_append (_tmp5_, ",");
				i = 1;
			}
		}
	}
	_tmp6_ = sb;
	_tmp7_ = sb;
	_tmp8_ = _tmp7_->len;
	_tmp9_ = i;
	g_string_truncate (_tmp6_, (gsize) (_tmp8_ - _tmp9_));
	_tmp10_ = sb;
	_tmp11_ = _tmp10_->str;
	_tmp12_ = g_strdup (_tmp11_);
	result = _tmp12_;
	_g_string_free0 (sb);
	return result;
}


gint* entitas_matcher_ListToArray (GList* list, int* result_length1) {
	gint* result = NULL;
	gint* a = NULL;
	GList* _tmp0_;
	guint _tmp1_;
	gint* _tmp2_;
	gint a_length1;
	gint _a_size_;
	gint i = 0;
	GList* _tmp3_;
	gint* _tmp8_;
	gint _tmp8__length1;
	_tmp0_ = list;
	_tmp1_ = g_list_length (_tmp0_);
	_tmp2_ = g_new0 (gint, _tmp1_);
	a = _tmp2_;
	a_length1 = _tmp1_;
	_a_size_ = a_length1;
	i = 0;
	_tmp3_ = list;
	{
		GList* x_collection = NULL;
		GList* x_it = NULL;
		x_collection = _tmp3_;
		for (x_it = x_collection; x_it != NULL; x_it = x_it->next) {
			gint x = 0;
			x = (gint) ((gintptr) x_it->data);
			{
				gint* _tmp4_;
				gint _tmp4__length1;
				gint _tmp5_;
				gint _tmp6_;
				gint _tmp7_;
				_tmp4_ = a;
				_tmp4__length1 = a_length1;
				_tmp5_ = i;
				i = _tmp5_ + 1;
				_tmp6_ = x;
				_tmp4_[_tmp5_] = _tmp6_;
				_tmp7_ = _tmp4_[_tmp5_];
			}
		}
	}
	_tmp8_ = a;
	_tmp8__length1 = a_length1;
	if (result_length1) {
		*result_length1 = _tmp8__length1;
	}
	result = _tmp8_;
	return result;
}


/**
 * Get the set if distinct (non-duplicate) indices from a list
 * @param indices array of indices to scrub
 * @return array of distint indices
 */
gint* entitas_matcher_DistinctIndices (gint* indices, int indices_length1, int* result_length1) {
	gint* result = NULL;
	gboolean* indicesSet = NULL;
	gboolean* _tmp0_;
	gint indicesSet_length1;
	gint _indicesSet_size_;
	GList* _result_ = NULL;
	gint* _tmp1_;
	gint _tmp1__length1;
	GList* _tmp9_;
	gint _tmp10_;
	gint* _tmp11_;
	gint* _tmp12_;
	gint _tmp12__length1;
	_tmp0_ = g_new0 (gboolean, 64);
	indicesSet = _tmp0_;
	indicesSet_length1 = 64;
	_indicesSet_size_ = indicesSet_length1;
	_result_ = NULL;
	_tmp1_ = indices;
	_tmp1__length1 = indices_length1;
	{
		gint* index_collection = NULL;
		gint index_collection_length1 = 0;
		gint _index_collection_size_ = 0;
		gint index_it = 0;
		index_collection = _tmp1_;
		index_collection_length1 = _tmp1__length1;
		for (index_it = 0; index_it < _tmp1__length1; index_it = index_it + 1) {
			gint index = 0;
			index = index_collection[index_it];
			{
				gboolean* _tmp2_;
				gint _tmp2__length1;
				gint _tmp3_;
				gboolean _tmp4_;
				gboolean* _tmp6_;
				gint _tmp6__length1;
				gint _tmp7_;
				gboolean _tmp8_;
				_tmp2_ = indicesSet;
				_tmp2__length1 = indicesSet_length1;
				_tmp3_ = index;
				_tmp4_ = _tmp2_[_tmp3_];
				if (!_tmp4_) {
					gint _tmp5_;
					_tmp5_ = index;
					_result_ = g_list_insert (_result_, (gpointer) ((gintptr) _tmp5_), 0);
				}
				_tmp6_ = indicesSet;
				_tmp6__length1 = indicesSet_length1;
				_tmp7_ = index;
				_tmp6_[_tmp7_] = TRUE;
				_tmp8_ = _tmp6_[_tmp7_];
			}
		}
	}
	_tmp9_ = _result_;
	_tmp11_ = entitas_matcher_ListToArray (_tmp9_, &_tmp10_);
	_tmp12_ = _tmp11_;
	_tmp12__length1 = _tmp10_;
	if (result_length1) {
		*result_length1 = _tmp12__length1;
	}
	result = _tmp12_;
	_g_list_free0 (_result_);
	indicesSet = (g_free (indicesSet), NULL);
	return result;
}


/**
 * Matches noneOf the components/indices specified
 * @param components list of components to match
 * @return new component matcher
 */
EntitasMatcher* entitas_matcher_NoneOf (gint* components, int components_length1) {
	EntitasMatcher* result = NULL;
	EntitasMatcher* matcher = NULL;
	EntitasMatcher* _tmp0_;
	gint* _tmp1_;
	gint _tmp1__length1;
	gint _tmp2_;
	gint* _tmp3_;
	gint* _tmp4_;
	gint _tmp4__length1;
	guint64 _tmp5_;
	_tmp0_ = entitas_matcher_new (NULL, 0);
	matcher = _tmp0_;
	_tmp1_ = components;
	_tmp1__length1 = components_length1;
	_tmp3_ = entitas_matcher_DistinctIndices (_tmp1_, _tmp1__length1, &_tmp2_);
	matcher->noneOfIndices = (g_free (matcher->noneOfIndices), NULL);
	matcher->noneOfIndices = _tmp3_;
	matcher->noneOfIndices_length1 = _tmp2_;
	_tmp4_ = matcher->noneOfIndices;
	_tmp4__length1 = matcher->noneOfIndices_length1;
	_tmp5_ = entitas_matcher_BuildMask (_tmp4_, _tmp4__length1);
	matcher->noneOfMask = _tmp5_;
	result = matcher;
	return result;
}


/**
 * Matches allOf the components/indices specified
 * @param components list of components to match
 * @return new component matcher
 */
EntitasMatcher* entitas_matcher_AllOf (gint* components, int components_length1) {
	EntitasMatcher* result = NULL;
	EntitasMatcher* matcher = NULL;
	EntitasMatcher* _tmp0_;
	gint* _tmp1_;
	gint _tmp1__length1;
	gint _tmp2_;
	gint* _tmp3_;
	gint* _tmp4_;
	gint _tmp4__length1;
	guint64 _tmp5_;
	_tmp0_ = entitas_matcher_new (NULL, 0);
	matcher = _tmp0_;
	_tmp1_ = components;
	_tmp1__length1 = components_length1;
	_tmp3_ = entitas_matcher_DistinctIndices (_tmp1_, _tmp1__length1, &_tmp2_);
	matcher->allOfIndices = (g_free (matcher->allOfIndices), NULL);
	matcher->allOfIndices = _tmp3_;
	matcher->allOfIndices_length1 = _tmp2_;
	_tmp4_ = matcher->allOfIndices;
	_tmp4__length1 = matcher->allOfIndices_length1;
	_tmp5_ = entitas_matcher_BuildMask (_tmp4_, _tmp4__length1);
	matcher->allOfMask = _tmp5_;
	result = matcher;
	return result;
}


/**
 * Matches anyOf the components/indices specified
 * @param components list of components to match
 * @return new component matcher
 */
EntitasMatcher* entitas_matcher_AnyOf (gint* components, int components_length1) {
	EntitasMatcher* result = NULL;
	EntitasMatcher* matcher = NULL;
	EntitasMatcher* _tmp0_;
	gint* _tmp1_;
	gint _tmp1__length1;
	gint _tmp2_;
	gint* _tmp3_;
	gint* _tmp4_;
	gint _tmp4__length1;
	guint64 _tmp5_;
	_tmp0_ = entitas_matcher_new (NULL, 0);
	matcher = _tmp0_;
	_tmp1_ = components;
	_tmp1__length1 = components_length1;
	_tmp3_ = entitas_matcher_DistinctIndices (_tmp1_, _tmp1__length1, &_tmp2_);
	matcher->anyOfIndices = (g_free (matcher->anyOfIndices), NULL);
	matcher->anyOfIndices = _tmp3_;
	matcher->anyOfIndices_length1 = _tmp2_;
	_tmp4_ = matcher->anyOfIndices;
	_tmp4__length1 = matcher->anyOfIndices_length1;
	_tmp5_ = entitas_matcher_BuildMask (_tmp4_, _tmp4__length1);
	matcher->anyOfMask = _tmp5_;
	result = matcher;
	return result;
}


guint64 entitas_matcher_BuildMask (gint* indices, int indices_length1) {
	guint64 result = 0ULL;
	guint64 accume = 0ULL;
	gint* _tmp0_;
	gint _tmp0__length1;
	accume = (guint64) 0;
	_tmp0_ = indices;
	_tmp0__length1 = indices_length1;
	{
		gint* index_collection = NULL;
		gint index_collection_length1 = 0;
		gint _index_collection_size_ = 0;
		gint index_it = 0;
		index_collection = _tmp0_;
		index_collection_length1 = _tmp0__length1;
		for (index_it = 0; index_it < _tmp0__length1; index_it = index_it + 1) {
			gint index = 0;
			index = index_collection[index_it];
			{
				guint64 _tmp1_;
				gint _tmp2_;
				guint64 _tmp3_;
				_tmp1_ = accume;
				_tmp2_ = index;
				_tmp3_ = ENTITAS_POW2[_tmp2_];
				accume = _tmp1_ | _tmp3_;
			}
		}
	}
	result = accume;
	return result;
}


static void entitas_matcher_instance_init (EntitasMatcher * self) {
	self->ref_count = 1;
}


void entitas_matcher_free (EntitasMatcher * self) {
	self->allOfIndices = (g_free (self->allOfIndices), NULL);
	self->anyOfIndices = (g_free (self->anyOfIndices), NULL);
	self->noneOfIndices = (g_free (self->noneOfIndices), NULL);
	self->indices = (g_free (self->indices), NULL);
	_g_free0 (self->toStringCache);
	g_slice_free (EntitasMatcher, self);
}




