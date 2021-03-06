/** updated by adriac */
/* entitas.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from entitas.vala, do not modify */

/*[Adriac:Entitas::System:EntitasSystem:entitas_system]*/
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

#define ENTITAS_TYPE_BUFFER (entitas_buffer_get_type ())
typedef struct _EntitasBuffer EntitasBuffer;

#define ENTITAS_TYPE_ISYSTEM (entitas_isystem_get_type ())
typedef struct _EntitasISystem EntitasISystem;
typedef struct _EntitasSystem EntitasSystem;

/**
 * ECS Exceptions
 */
typedef enum  {
	ENTITAS_EXCEPTION_EntityIsNotEnabled,
	ENTITAS_EXCEPTION_EntityAlreadyHasComponent,
	ENTITAS_EXCEPTION_EntityDoesNotHaveComponent,
	ENTITAS_EXCEPTION_InvalidMatcherExpression,
	ENTITAS_EXCEPTION_EntityIsAlreadyReleased,
	ENTITAS_EXCEPTION_SingleEntity,
	ENTITAS_EXCEPTION_WorldDoesNotContainEntity
} EntitasException;
#define ENTITAS_EXCEPTION entitas_exception_quark ()
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

typedef EntitasEntity* (*EntitasEntityFactory) (void* user_data);
typedef void (*EntitasSystemInitialize) (void* user_data);
typedef void (*EntitasSystemExecute) (gfloat delta, void* user_data);
struct _EntitasBuffer {
	gint pool;
	gint size;
	EntitasEntityFactory Factory;
	gpointer Factory_target;
	GDestroyNotify Factory_target_destroy_notify;
};

struct _EntitasISystem {
	EntitasSystemInitialize Initialize;
	gpointer Initialize_target;
	GDestroyNotify Initialize_target_destroy_notify;
	EntitasSystemExecute Execute;
	gpointer Execute_target;
	GDestroyNotify Execute_target_destroy_notify;
};

struct _EntitasSystem {
	gint ref_count;
	EntitasSystemInitialize Initialize;
	gpointer Initialize_target;
	GDestroyNotify Initialize_target_destroy_notify;
	EntitasSystemExecute Execute;
	gpointer Execute_target;
	GDestroyNotify Execute_target_destroy_notify;
};



GQuark entitas_exception_quark (void);
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
GType entitas_buffer_get_type (void) G_GNUC_CONST;
EntitasBuffer* entitas_buffer_dup (const EntitasBuffer* self);
void entitas_buffer_free (EntitasBuffer* self);
void entitas_buffer_copy (const EntitasBuffer* self, EntitasBuffer* dest);
void entitas_buffer_destroy (EntitasBuffer* self);
void entitas_buffer_init (EntitasBuffer *self, gint pool, gint size, EntitasEntityFactory factory, void* factory_target);
GType entitas_isystem_get_type (void) G_GNUC_CONST;
EntitasISystem* entitas_isystem_dup (const EntitasISystem* self);
void entitas_isystem_free (EntitasISystem* self);
void entitas_isystem_copy (const EntitasISystem* self, EntitasISystem* dest);
void entitas_isystem_destroy (EntitasISystem* self);
void entitas_system_free (EntitasSystem * self);
static void entitas_system_instance_init (EntitasSystem * self);
static void _entitas_system_initialize_lambda13_ (void);
static void __entitas_system_initialize_lambda13__entitas_system_initialize (gpointer self);
static void _entitas_system_execute_lambda14_ (gfloat delta);
static void __entitas_system_execute_lambda14__entitas_system_execute (gfloat delta, gpointer self);
EntitasSystem* entitas_system_retain (EntitasSystem* self);
void entitas_system_release (EntitasSystem* self);
void entitas_system_free (EntitasSystem* self);
EntitasSystem* entitas_system_new (void);
void entitas_system_get_ISystem (EntitasSystem* self, EntitasISystem * result);

const guint64 ENTITAS_POW2[65] = {(guint64) 0x0000000000000000, (guint64) 0x0000000000000001, (guint64) 0x0000000000000002, (guint64) 0x0000000000000004, (guint64) 0x0000000000000008, (guint64) 0x0000000000000010, (guint64) 0x0000000000000020, (guint64) 0x0000000000000040, (guint64) 0x0000000000000080, (guint64) 0x0000000000000100, (guint64) 0x0000000000000200, (guint64) 0x0000000000000400, (guint64) 0x0000000000000800, (guint64) 0x0000000000001000, (guint64) 0x0000000000002000, (guint64) 0x0000000000004000, (guint64) 0x0000000000008000, (guint64) 0x0000000000010000, (guint64) 0x0000000000020000, (guint64) 0x0000000000040000, (guint64) 0x0000000000080000, (guint64) 0x0000000000100000, (guint64) 0x0000000000200000, (guint64) 0x0000000000400000, (guint64) 0x0000000000800000, (guint64) 0x0000000001000000, (guint64) 0x0000000002000000, (guint64) 0x0000000004000000, (guint64) 0x0000000008000000, (guint64) 0x0000000010000000, (guint64) 0x0000000020000000, (guint64) 0x0000000040000000, (guint64) 0x0000000080000000LL, (guint64) 0x0000000100000000LL, (guint64) 0x0000000200000000LL, (guint64) 0x0000000400000000LL, (guint64) 0x0000000800000000LL, (guint64) 0x0000001000000000LL, (guint64) 0x0000002000000000LL, (guint64) 0x0000004000000000LL, (guint64) 0x0000008000000000LL, (guint64) 0x0000010000000000LL, (guint64) 0x0000020000000000LL, (guint64) 0x0000040000000000LL, (guint64) 0x0000080000000000LL, (guint64) 0x0000100000000000LL, (guint64) 0x0000200000000000LL, (guint64) 0x0000400000000000LL, (guint64) 0x0000800000000000LL, (guint64) 0x0001000000000000LL, (guint64) 0x0002000000000000LL, (guint64) 0x0004000000000000LL, (guint64) 0x0008000000000000LL, (guint64) 0x0010000000000000LL, (guint64) 0x0020000000000000LL, (guint64) 0x0040000000000000LL, (guint64) 0x0080000000000000LL, (guint64) 0x0100000000000000LL, (guint64) 0x0200000000000000LL, (guint64) 0x0400000000000000LL, (guint64) 0x0800000000000000LL, (guint64) 0x1000000000000000LL, (guint64) 0x2000000000000000LL, (guint64) 0x4000000000000000LL, (guint64) 0x8000000000000000LL};

GQuark entitas_exception_quark (void) {
	return g_quark_from_static_string ("entitas_exception-quark");
}


void entitas_buffer_init (EntitasBuffer *self, gint pool, gint size, EntitasEntityFactory factory, void* factory_target) {
	gint _tmp0_;
	gint _tmp1_;
	EntitasEntityFactory _tmp2_;
	void* _tmp2__target;
	memset (self, 0, sizeof (EntitasBuffer));
	_tmp0_ = pool;
	(*self).pool = _tmp0_;
	_tmp1_ = size;
	(*self).size = _tmp1_;
	_tmp2_ = factory;
	_tmp2__target = factory_target;
	((*self).Factory_target_destroy_notify == NULL) ? NULL : ((*self).Factory_target_destroy_notify ((*self).Factory_target), NULL);
	(*self).Factory = NULL;
	(*self).Factory_target = NULL;
	(*self).Factory_target_destroy_notify = NULL;
	(*self).Factory = _tmp2_;
	(*self).Factory_target = _tmp2__target;
	(*self).Factory_target_destroy_notify = NULL;
}


void entitas_buffer_copy (const EntitasBuffer* self, EntitasBuffer* dest) {
	gint _tmp0_;
	gint _tmp1_;
	EntitasEntityFactory _tmp2_;
	void* _tmp2__target;
	_tmp0_ = (*self).pool;
	(*dest).pool = _tmp0_;
	_tmp1_ = (*self).size;
	(*dest).size = _tmp1_;
	_tmp2_ = (*self).Factory;
	_tmp2__target = (*self).Factory_target;
	((*dest).Factory_target_destroy_notify == NULL) ? NULL : ((*dest).Factory_target_destroy_notify ((*dest).Factory_target), NULL);
	(*dest).Factory = NULL;
	(*dest).Factory_target = NULL;
	(*dest).Factory_target_destroy_notify = NULL;
	(*dest).Factory = _tmp2_;
	(*dest).Factory_target = _tmp2__target;
	(*dest).Factory_target_destroy_notify = NULL;
}


void entitas_buffer_destroy (EntitasBuffer* self) {
	((*self).Factory_target_destroy_notify == NULL) ? NULL : ((*self).Factory_target_destroy_notify ((*self).Factory_target), NULL);
	(*self).Factory = NULL;
	(*self).Factory_target = NULL;
	(*self).Factory_target_destroy_notify = NULL;
}


EntitasBuffer* entitas_buffer_dup (const EntitasBuffer* self) {
	EntitasBuffer* dup;
	dup = g_new0 (EntitasBuffer, 1);
	entitas_buffer_copy (self, dup);
	return dup;
}


void entitas_buffer_free (EntitasBuffer* self) {
	entitas_buffer_destroy (self);
	g_free (self);
}


GType entitas_buffer_get_type (void) {
	static volatile gsize entitas_buffer_type_id__volatile = 0;
	if (g_once_init_enter (&entitas_buffer_type_id__volatile)) {
		GType entitas_buffer_type_id;
		entitas_buffer_type_id = g_boxed_type_register_static ("EntitasBuffer", (GBoxedCopyFunc) entitas_buffer_dup, (GBoxedFreeFunc) entitas_buffer_free);
		g_once_init_leave (&entitas_buffer_type_id__volatile, entitas_buffer_type_id);
	}
	return entitas_buffer_type_id__volatile;
}


void entitas_isystem_copy (const EntitasISystem* self, EntitasISystem* dest) {
	EntitasSystemInitialize _tmp0_;
	void* _tmp0__target;
	EntitasSystemExecute _tmp1_;
	void* _tmp1__target;
	_tmp0_ = (*self).Initialize;
	_tmp0__target = (*self).Initialize_target;
	((*dest).Initialize_target_destroy_notify == NULL) ? NULL : ((*dest).Initialize_target_destroy_notify ((*dest).Initialize_target), NULL);
	(*dest).Initialize = NULL;
	(*dest).Initialize_target = NULL;
	(*dest).Initialize_target_destroy_notify = NULL;
	(*dest).Initialize = _tmp0_;
	(*dest).Initialize_target = _tmp0__target;
	(*dest).Initialize_target_destroy_notify = NULL;
	_tmp1_ = (*self).Execute;
	_tmp1__target = (*self).Execute_target;
	((*dest).Execute_target_destroy_notify == NULL) ? NULL : ((*dest).Execute_target_destroy_notify ((*dest).Execute_target), NULL);
	(*dest).Execute = NULL;
	(*dest).Execute_target = NULL;
	(*dest).Execute_target_destroy_notify = NULL;
	(*dest).Execute = _tmp1_;
	(*dest).Execute_target = _tmp1__target;
	(*dest).Execute_target_destroy_notify = NULL;
}


void entitas_isystem_destroy (EntitasISystem* self) {
	((*self).Initialize_target_destroy_notify == NULL) ? NULL : ((*self).Initialize_target_destroy_notify ((*self).Initialize_target), NULL);
	(*self).Initialize = NULL;
	(*self).Initialize_target = NULL;
	(*self).Initialize_target_destroy_notify = NULL;
	((*self).Execute_target_destroy_notify == NULL) ? NULL : ((*self).Execute_target_destroy_notify ((*self).Execute_target), NULL);
	(*self).Execute = NULL;
	(*self).Execute_target = NULL;
	(*self).Execute_target_destroy_notify = NULL;
}


EntitasISystem* entitas_isystem_dup (const EntitasISystem* self) {
	EntitasISystem* dup;
	dup = g_new0 (EntitasISystem, 1);
	entitas_isystem_copy (self, dup);
	return dup;
}


void entitas_isystem_free (EntitasISystem* self) {
	entitas_isystem_destroy (self);
	g_free (self);
}


GType entitas_isystem_get_type (void) {
	static volatile gsize entitas_isystem_type_id__volatile = 0;
	if (g_once_init_enter (&entitas_isystem_type_id__volatile)) {
		GType entitas_isystem_type_id;
		entitas_isystem_type_id = g_boxed_type_register_static ("EntitasISystem", (GBoxedCopyFunc) entitas_isystem_dup, (GBoxedFreeFunc) entitas_isystem_free);
		g_once_init_leave (&entitas_isystem_type_id__volatile, entitas_isystem_type_id);
	}
	return entitas_isystem_type_id__volatile;
}


static void _entitas_system_initialize_lambda13_ (void) {
}


static void __entitas_system_initialize_lambda13__entitas_system_initialize (gpointer self) {
	_entitas_system_initialize_lambda13_ ();
}


static void _entitas_system_execute_lambda14_ (gfloat delta) {
}


static void __entitas_system_execute_lambda14__entitas_system_execute (gfloat delta, gpointer self) {
	_entitas_system_execute_lambda14_ (delta);
}


EntitasSystem* entitas_system_retain (EntitasSystem* self) {
	EntitasSystem* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->ref_count), 1);
	result = self;
	return result;
}


void entitas_system_release (EntitasSystem* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->ref_count));
	if (_tmp0_) {
		entitas_system_free (self);
	}
}


EntitasSystem* entitas_system_new (void) {
	EntitasSystem* self;
	self = g_slice_new0 (EntitasSystem);
	entitas_system_instance_init (self);
	return self;
}


void entitas_system_get_ISystem (EntitasSystem* self, EntitasISystem * result) {
	EntitasSystemInitialize _tmp0_;
	void* _tmp0__target;
	EntitasSystemExecute _tmp1_;
	void* _tmp1__target;
	EntitasISystem _tmp2_ = {0};
	g_return_if_fail (self != NULL);
	_tmp0_ = self->Initialize;
	_tmp0__target = self->Initialize_target;
	_tmp1_ = self->Execute;
	_tmp1__target = self->Execute_target;
	(_tmp2_.Initialize_target_destroy_notify == NULL) ? NULL : (_tmp2_.Initialize_target_destroy_notify (_tmp2_.Initialize_target), NULL);
	_tmp2_.Initialize = NULL;
	_tmp2_.Initialize_target = NULL;
	_tmp2_.Initialize_target_destroy_notify = NULL;
	_tmp2_.Initialize = _tmp0_;
	_tmp2_.Initialize_target = _tmp0__target;
	_tmp2_.Initialize_target_destroy_notify = NULL;
	(_tmp2_.Execute_target_destroy_notify == NULL) ? NULL : (_tmp2_.Execute_target_destroy_notify (_tmp2_.Execute_target), NULL);
	_tmp2_.Execute = NULL;
	_tmp2_.Execute_target = NULL;
	_tmp2_.Execute_target_destroy_notify = NULL;
	_tmp2_.Execute = _tmp1_;
	_tmp2_.Execute_target = _tmp1__target;
	_tmp2_.Execute_target_destroy_notify = NULL;
	*result = _tmp2_;
	return;
}


static void entitas_system_instance_init (EntitasSystem * self) {
	self->ref_count = 1;
	self->Initialize = __entitas_system_initialize_lambda13__entitas_system_initialize;
	self->Initialize_target = self;
	self->Initialize_target_destroy_notify = NULL;
	self->Execute = __entitas_system_execute_lambda14__entitas_system_execute;
	self->Execute_target = self;
	self->Execute_target_destroy_notify = NULL;
}


void entitas_system_free (EntitasSystem * self) {
	(self->Initialize_target_destroy_notify == NULL) ? NULL : (self->Initialize_target_destroy_notify (self->Initialize_target), NULL);
	self->Initialize = NULL;
	self->Initialize_target = NULL;
	self->Initialize_target_destroy_notify = NULL;
	(self->Execute_target_destroy_notify == NULL) ? NULL : (self->Execute_target_destroy_notify (self->Execute_target), NULL);
	self->Execute = NULL;
	self->Execute_target = NULL;
	self->Execute_target_destroy_notify = NULL;
	g_slice_free (EntitasSystem, self);
}




