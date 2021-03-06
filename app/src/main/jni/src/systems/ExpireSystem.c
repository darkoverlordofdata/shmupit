/** updated by adriac */
/* ExpireSystem.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from ExpireSystem.vala, do not modify */

/*[Adriac:Systems::ExpireSystem:SystemsExpireSystem:systems_expire_system]*/

#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <SDL_rect.h>

typedef struct _EntitasSystem EntitasSystem;
typedef EntitasSystem SystemsExpireSystem;
typedef struct _SdxAbstractGame SdxAbstractGame;
typedef SdxAbstractGame Game;
typedef struct _EntitasWorld EntitasWorld;
typedef EntitasWorld Factory;
typedef struct _EntitasGroup EntitasGroup;
// symtbl.1 entitas_world
void entitas_world_release (EntitasWorld* self);
void entitas_world_free (EntitasWorld* self);
EntitasWorld* entitas_world_retain (EntitasWorld* self);
#define _entitas_world_release0(var) ((var == NULL) ? NULL : (var = (entitas_world_release (var), NULL)))
typedef struct _Block31Data Block31Data;
// symtbl.1 entitas_group
void entitas_group_release (EntitasGroup* self);
void entitas_group_free (EntitasGroup* self);
EntitasGroup* entitas_group_retain (EntitasGroup* self);
#define _entitas_group_release0(var) ((var == NULL) ? NULL : (var = (entitas_group_release (var), NULL)))
// symtbl.1 entitas_system
void entitas_system_release (EntitasSystem* self);
void entitas_system_free (EntitasSystem* self);
EntitasSystem* entitas_system_retain (EntitasSystem* self);
#define _entitas_system_release0(var) ((var == NULL) ? NULL : (var = (entitas_system_release (var), NULL)))
typedef struct _EntitasMatcher EntitasMatcher;

#define ENTITAS_TYPE_COMPONENTS (entitas_components_get_type ())
// symtbl.1 entitas_matcher
void entitas_matcher_release (EntitasMatcher* self);
void entitas_matcher_free (EntitasMatcher* self);
EntitasMatcher* entitas_matcher_retain (EntitasMatcher* self);
#define _entitas_matcher_release0(var) ((var == NULL) ? NULL : (var = (entitas_matcher_release (var), NULL)))
typedef struct _Block32Data Block32Data;

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
typedef struct _EntitasEventGroupChanged EntitasEventGroupChanged;
typedef struct _EntitasEventGroupUpdated EntitasEventGroupUpdated;

typedef void (*EntitasSystemInitialize) (void* user_data);
typedef void (*EntitasSystemExecute) (gfloat delta, void* user_data);
struct _EntitasSystem {
	gint ref_count;
	EntitasSystemInitialize Initialize;
	gpointer Initialize_target;
	GDestroyNotify Initialize_target_destroy_notify;
	EntitasSystemExecute Execute;
	gpointer Execute_target;
	GDestroyNotify Execute_target_destroy_notify;
};

struct _Block31Data {
	int _ref_count_;
	SystemsExpireSystem* self;
	EntitasGroup* expiring;
	Factory* world;
};

typedef enum  {
	ENTITAS_COMPONENTS_UnknownComponent,
	ENTITAS_COMPONENTS_BackgroundComponent,
	ENTITAS_COMPONENTS_BulletComponent,
	ENTITAS_COMPONENTS_Enemy1Component,
	ENTITAS_COMPONENTS_Enemy2Component,
	ENTITAS_COMPONENTS_Enemy3Component,
	ENTITAS_COMPONENTS_ExpiresComponent,
	ENTITAS_COMPONENTS_HealthComponent,
	ENTITAS_COMPONENTS_HudComponent,
	ENTITAS_COMPONENTS_LayerComponent,
	ENTITAS_COMPONENTS_PlayerComponent,
	ENTITAS_COMPONENTS_ShowComponent,
	ENTITAS_COMPONENTS_SoundComponent,
	ENTITAS_COMPONENTS_TextComponent,
	ENTITAS_COMPONENTS_TintComponent,
	ENTITAS_COMPONENTS_TweenComponent,
	ENTITAS_COMPONENTS_VelocityComponent
} EntitasComponents;

struct _Block32Data {
	int _ref_count_;
	Block31Data * _data31_;
	gfloat delta;
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

struct _EntitasGroup {
	gint ref_count;
	GList* entities;
	EntitasMatcher* matcher;
	EntitasEventGroupChanged* onEntityAdded;
	EntitasEventGroupChanged* onEntityRemoved;
	EntitasEventGroupUpdated* onEntityUpdated;
};



void entitas_system_free (EntitasSystem * self);
void sdx_abstract_game_free (SdxAbstractGame * self);
void entitas_world_free (EntitasWorld * self);
SystemsExpireSystem* systems_expire_system_new (Game* game, Factory* world);
void entitas_group_free (EntitasGroup * self);
static Block31Data* block31_data_ref (Block31Data* _data31_);
static void block31_data_unref (void * _userdata_);
EntitasSystem* entitas_system_new (void);
void entitas_matcher_free (EntitasMatcher * self);
EntitasGroup* entitas_world_GetGroup (EntitasWorld* self, EntitasMatcher* matcher);
EntitasMatcher* entitas_matcher_AllOf (gint* components, int components_length1);
GType entitas_components_get_type (void) G_GNUC_CONST;
static void __lambda133_ (Block31Data* _data31_, gfloat delta);
static Block32Data* block32_data_ref (Block32Data* _data32_);
static void block32_data_unref (void * _userdata_);
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
void entitas_event_group_changed_free (EntitasEventGroupChanged * self);
void entitas_event_group_updated_free (EntitasEventGroupUpdated * self);
static void __lambda134_ (Block32Data* _data32_, EntitasEntity* entity);
gboolean entitas_entity_IsActive (EntitasEntity *self);
void entitas_world_DeleteEntity (EntitasWorld* self, EntitasEntity* entity);
EntitasEntity* entitas_entity_SetShow (EntitasEntity *self, gboolean value);
static void ___lambda134__gfunc (gconstpointer data, gpointer self);
static void ___lambda133__entitas_system_execute (gfloat delta, gpointer self);


static gpointer _entitas_world_retain0 (gpointer self) {
	return self ? entitas_world_retain (self) : NULL;
}


static Block31Data* block31_data_ref (Block31Data* _data31_) {
	g_atomic_int_inc (&_data31_->_ref_count_);
	return _data31_;
}


static void block31_data_unref (void * _userdata_) {
	Block31Data* _data31_;
	_data31_ = (Block31Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data31_->_ref_count_)) {
		SystemsExpireSystem* self;
		self = _data31_->self;
		_entitas_group_release0 (_data31_->expiring);
		_entitas_world_release0 (_data31_->world);
		_entitas_system_release0 (self);
		g_slice_free (Block31Data, _data31_);
	}
}


static Block32Data* block32_data_ref (Block32Data* _data32_) {
	g_atomic_int_inc (&_data32_->_ref_count_);
	return _data32_;
}


static void block32_data_unref (void * _userdata_) {
	Block32Data* _data32_;
	_data32_ = (Block32Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data32_->_ref_count_)) {
		SystemsExpireSystem* self;
		self = _data32_->_data31_->self;
		block31_data_unref (_data32_->_data31_);
		_data32_->_data31_ = NULL;
		g_slice_free (Block32Data, _data32_);
	}
}


static void __lambda134_ (Block32Data* _data32_, EntitasEntity* entity) {
	Block31Data* _data31_;
	SystemsExpireSystem* self;
	gboolean _tmp0_;
	_data31_ = _data32_->_data31_;
	self = _data31_->self;
	_tmp0_ = entitas_entity_IsActive (entity);
	if (_tmp0_) {
		EntitasEntity* _tmp1_;
		EntitasExpires* _tmp2_;
		EntitasEntity* _tmp3_;
		EntitasExpires* _tmp4_;
		gfloat _tmp5_;
		gfloat _tmp6_;
		EntitasEntity* _tmp7_;
		EntitasExpires* _tmp8_;
		gfloat _tmp9_;
		_tmp1_ = entity;
		_tmp2_ = (*_tmp1_).expires;
		_tmp3_ = entity;
		_tmp4_ = (*_tmp3_).expires;
		_tmp5_ = (*_tmp4_).value;
		_tmp6_ = _data32_->delta;
		(*_tmp4_).value = _tmp5_ - _tmp6_;
		_tmp7_ = entity;
		_tmp8_ = (*_tmp7_).expires;
		_tmp9_ = (*_tmp8_).value;
		if (_tmp9_ < ((gfloat) 0)) {
			Factory* _tmp10_;
			EntitasEntity* _tmp11_;
			_tmp10_ = _data31_->world;
			_tmp11_ = entitas_entity_SetShow (entity, FALSE);
			entitas_world_DeleteEntity ((EntitasWorld*) _tmp10_, _tmp11_);
		}
	}
}


static void ___lambda134__gfunc (gconstpointer data, gpointer self) {
	__lambda134_ (self, data);
}


static void __lambda133_ (Block31Data* _data31_, gfloat delta) {
	SystemsExpireSystem* self;
	Block32Data* _data32_;
	gfloat _tmp0_;
	GList* _tmp1_;
	self = _data31_->self;
	_data32_ = g_slice_new0 (Block32Data);
	_data32_->_ref_count_ = 1;
	_data32_->_data31_ = block31_data_ref (_data31_);
	_tmp0_ = delta;
	_data32_->delta = _tmp0_;
	_tmp1_ = _data31_->expiring->entities;
	g_list_foreach (_tmp1_, ___lambda134__gfunc, _data32_);
	block32_data_unref (_data32_);
	_data32_ = NULL;
}


static void ___lambda133__entitas_system_execute (gfloat delta, gpointer self) {
	__lambda133_ (self, delta);
}


SystemsExpireSystem* systems_expire_system_new (Game* game, Factory* world) {
	SystemsExpireSystem* self;
	Block31Data* _data31_;
	Factory* _tmp0_;
	Factory* _tmp1_;
	Factory* _tmp2_;
	gint* _tmp3_;
	gint* _tmp4_;
	gint _tmp4__length1;
	EntitasMatcher* _tmp5_;
	EntitasMatcher* _tmp6_;
	EntitasGroup* _tmp7_;
	EntitasGroup* _tmp8_;
	g_return_val_if_fail (game != NULL, NULL);
	g_return_val_if_fail (world != NULL, NULL);
	_data31_ = g_slice_new0 (Block31Data);
	_data31_->_ref_count_ = 1;
	_tmp0_ = world;
	_tmp1_ = _entitas_world_retain0 (_tmp0_);
	_entitas_world_release0 (_data31_->world);
	_data31_->world = _tmp1_;
	self = (SystemsExpireSystem*) entitas_system_new ();
	_data31_->self = entitas_system_retain (self);
	_tmp2_ = _data31_->world;
	_tmp3_ = g_new0 (gint, 1);
	_tmp3_[0] = (gint) ENTITAS_COMPONENTS_ExpiresComponent;
	_tmp4_ = _tmp3_;
	_tmp4__length1 = 1;
	_tmp5_ = entitas_matcher_AllOf (_tmp4_, 1);
	_tmp6_ = _tmp5_;
	_tmp7_ = entitas_world_GetGroup ((EntitasWorld*) _tmp2_, _tmp6_);
	_tmp8_ = _tmp7_;
	_entitas_matcher_release0 (_tmp6_);
	_tmp4_ = (g_free (_tmp4_), NULL);
	_data31_->expiring = _tmp8_;
	(((EntitasSystem*) self)->Execute_target_destroy_notify == NULL) ? NULL : (((EntitasSystem*) self)->Execute_target_destroy_notify (((EntitasSystem*) self)->Execute_target), NULL);
	((EntitasSystem*) self)->Execute = NULL;
	((EntitasSystem*) self)->Execute_target = NULL;
	((EntitasSystem*) self)->Execute_target_destroy_notify = NULL;
	((EntitasSystem*) self)->Execute = ___lambda133__entitas_system_execute;
	((EntitasSystem*) self)->Execute_target = block31_data_ref (_data31_);
	((EntitasSystem*) self)->Execute_target_destroy_notify = block31_data_unref;
	block31_data_unref (_data31_);
	_data31_ = NULL;
	return self;
}




