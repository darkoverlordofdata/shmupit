/** updated by adriac */
/* Label.c generated by valac 0.36.4-dirty, the Vala compiler
 * generated from Label.vala, do not modify */

/*[Adriac:Sdx.Ui::Container:SdxUiContainer:sdx_ui_container]*/
/*[Adriac:Sdx.Ui:Label:NinePatch:SdxUiLabelNinePatch:sdx_ui_label_ninepatch]*/
/*[Adriac:Sdx.Ui::Label:SdxUiLabel:sdx_ui_label]*/
/*[Adriac:Sdx.Ui:Label:Text:SdxUiLabelText:sdx_ui_label_text]*/
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
#include <SDL_video.h>
#include <SDL_rect.h>
#include <SDL_pixels.h>
#include <stdlib.h>
#include <string.h>
#include <SDL_render.h>
#include <float.h>
#include <math.h>

typedef struct _SdxUiComponent SdxUiComponent;

#define SDX_UI_COMPONENT_TYPE_KIND (sdx_ui_component_kind_get_type ())
typedef struct _SdxFont SdxFont;
typedef struct _SdxGraphicsSprite SdxGraphicsSprite;
typedef struct _SdxInputProcessor SdxInputProcessor;
typedef SdxUiComponent SdxUiContainer;
// symtbl.1 sdx_graphics_sprite
void sdx_graphics_sprite_release (SdxGraphicsSprite* self);
void sdx_graphics_sprite_free (SdxGraphicsSprite* self);
SdxGraphicsSprite* sdx_graphics_sprite_retain (SdxGraphicsSprite* self);
#define _sdx_graphics_sprite_release0(var) ((var == NULL) ? NULL : (var = (sdx_graphics_sprite_release (var), NULL)))
typedef struct _Class Class;

#define SDX_GRAPHICS_SPRITE_TYPE_KIND (sdx_graphics_sprite_kind_get_type ())

#define SDX_MATH_TYPE_SCALE (sdx_math_scale_get_type ())
typedef struct _SdxMathScale SdxMathScale;
typedef SdxUiComponent SdxUiLabel;
typedef SdxUiLabel SdxUiLabelText;
#define _g_free0(var) (var = (g_free (var), NULL))
// symtbl.1 sdx_font
void sdx_font_release (SdxFont* self);
void sdx_font_free (SdxFont* self);
SdxFont* sdx_font_retain (SdxFont* self);
#define _sdx_font_release0(var) ((var == NULL) ? NULL : (var = (sdx_font_release (var), NULL)))
typedef SdxGraphicsSprite SdxGraphicsSpriteTextSprite;
typedef SdxUiLabel SdxUiLabelNinePatch;
typedef struct _SdxGraphicsNinePatch SdxGraphicsNinePatch;
typedef SdxGraphicsSprite SdxGraphicsSpriteUISprite;

typedef enum  {
	SDX_UI_COMPONENT_KIND_Window,
	SDX_UI_COMPONENT_KIND_Label,
	SDX_UI_COMPONENT_KIND_Button
} SdxUiComponentKind;

typedef void (*SdxUiComponentComponentOnMouseClick) (SdxUiComponent* c, gint x, gint y, void* user_data);
typedef void (*SdxUiComponentComponentOnMouseEnter) (SdxUiComponent* c, gint x, gint y, void* user_data);
typedef void (*SdxUiComponentComponentOnMouseLeave) (SdxUiComponent* c, gint x, gint y, void* user_data);
typedef void (*SdxUiComponentComponentStart) (void* user_data);
struct _SdxUiComponent {
	gint ref_count;
	SdxUiComponentKind kind;
	SdxUiComponent* parent;
	SDL_Window* root;
	SDL_Rect* bounds;
	SDL_Color* foreground;
	SDL_Color* background;
	SdxFont* font;
	gboolean visible;
	gboolean enabled;
	gboolean valid;
	gchar* name;
	gboolean focus;
	gboolean selected;
	gchar* text;
	GList* controls;
	SdxGraphicsSprite** image;
	gint image_length1;
	gint index;
	SdxInputProcessor* handler;
	SdxUiComponentComponentOnMouseClick OnMouseClick;
	gpointer OnMouseClick_target;
	GDestroyNotify OnMouseClick_target_destroy_notify;
	SdxUiComponentComponentOnMouseEnter OnMouseEnter;
	gpointer OnMouseEnter_target;
	GDestroyNotify OnMouseEnter_target_destroy_notify;
	SdxUiComponentComponentOnMouseLeave OnMouseLeave;
	gpointer OnMouseLeave_target;
	GDestroyNotify OnMouseLeave_target_destroy_notify;
	SdxUiComponentComponentStart Start;
	gpointer Start_target;
	GDestroyNotify Start_target_destroy_notify;
	SdxUiComponentComponentStart Stop;
	gpointer Stop_target;
	GDestroyNotify Stop_target_destroy_notify;
};

typedef enum  {
	SDX_GRAPHICS_SPRITE_KIND_AnimatedSprite,
	SDX_GRAPHICS_SPRITE_KIND_TextureSprite,
	SDX_GRAPHICS_SPRITE_KIND_AtlasSprite,
	SDX_GRAPHICS_SPRITE_KIND_NineSliceSprite,
	SDX_GRAPHICS_SPRITE_KIND_CompositeSprite,
	SDX_GRAPHICS_SPRITE_KIND_TextSprite
} SdxGraphicsSpriteKind;

struct _SdxMathScale {
	gfloat x;
	gfloat y;
};

struct _SdxGraphicsSprite {
	gint ref_count;
	Class* klass;
	SdxGraphicsSpriteKind kind;
	gint id;
	SDL_Texture* texture;
	gint width;
	gint height;
	gint x;
	gint y;
	gint index;
	gint frame;
	gdouble angle;
	SdxMathScale scale;
	SDL_Color color;
	SDL_RendererFlip flip;
	SDL_Point center;
	gboolean centered;
	gint layer;
	gchar* path;
};



void sdx_ui_component_free (SdxUiComponent * self);
GType sdx_ui_component_kind_get_type (void) G_GNUC_CONST;
void sdx_font_free (SdxFont * self);
void sdx_graphics_sprite_free (SdxGraphicsSprite * self);
void sdx_input_processor_free (SdxInputProcessor * self);
SdxUiContainer* sdx_ui_container_new (SdxGraphicsSprite* sprite);
SdxUiComponent* sdx_ui_component_new (gint x, gint y, gint w, gint h);
SdxGraphicsSprite* sdx_graphics_sprite_SetCentered (SdxGraphicsSprite* self, gboolean value);
void class_free (Class * self);
GType sdx_graphics_sprite_kind_get_type (void) G_GNUC_CONST;
GType sdx_math_scale_get_type (void) G_GNUC_CONST;
SdxMathScale* sdx_math_scale_dup (const SdxMathScale* self);
void sdx_math_scale_free (SdxMathScale* self);
SdxUiLabel* sdx_ui_label_new (void);
SdxUiLabelText* sdx_ui_label_text_new (const gchar* text, SdxFont* font, SDL_Color fg, SDL_Color* bg);
static SDL_Color* _sdl_video_color_dup (SDL_Color* self);
SdxGraphicsSpriteTextSprite* sdx_graphics_sprite_text_sprite_new (const gchar* text, SdxFont* font, SDL_Color fg, SDL_Color* bg);
void sdx_graphics_nine_patch_free (SdxGraphicsNinePatch * self);
SdxUiLabelNinePatch* sdx_ui_label_nine_patch_new (const gchar* text, SdxFont* font, SDL_Color fg, SdxGraphicsNinePatch* bg);
SdxGraphicsSpriteUISprite* sdx_graphics_sprite_ui_sprite_new (SdxGraphicsNinePatch* patch, const gchar* text, SdxFont* font, SDL_Color color, gint width, gint height);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gpointer _sdx_graphics_sprite_retain0 (gpointer self) {
	return self ? sdx_graphics_sprite_retain (self) : NULL;
}


SdxUiContainer* sdx_ui_container_new (SdxGraphicsSprite* sprite) {
	SdxUiContainer* self;
	SdxGraphicsSprite* _tmp0_;
	SdxGraphicsSprite* _tmp1_;
	SdxGraphicsSprite** _tmp2_;
	SdxGraphicsSprite** _tmp3_;
	gint _tmp3__length1;
	SdxGraphicsSprite* _tmp4_;
	SdxGraphicsSprite* _tmp5_;
	SdxGraphicsSprite* _tmp6_;
	SDL_Rect* _tmp7_;
	SdxGraphicsSprite** _tmp8_;
	gint _tmp8__length1;
	SdxGraphicsSprite* _tmp9_;
	gint _tmp10_;
	SDL_Rect* _tmp11_;
	SdxGraphicsSprite** _tmp12_;
	gint _tmp12__length1;
	SdxGraphicsSprite* _tmp13_;
	gint _tmp14_;
	g_return_val_if_fail (sprite != NULL, NULL);
	self = (SdxUiContainer*) sdx_ui_component_new (0, 0, 0, 0);
	_tmp0_ = sprite;
	_tmp1_ = _sdx_graphics_sprite_retain0 (_tmp0_);
	_tmp2_ = g_new0 (SdxGraphicsSprite*, 1 + 1);
	_tmp2_[0] = _tmp1_;
	((SdxUiComponent*) self)->image = (_vala_array_free (((SdxUiComponent*) self)->image, ((SdxUiComponent*) self)->image_length1, (GDestroyNotify) sdx_graphics_sprite_release), NULL);
	((SdxUiComponent*) self)->image = _tmp2_;
	((SdxUiComponent*) self)->image_length1 = 1;
	_tmp3_ = ((SdxUiComponent*) self)->image;
	_tmp3__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp4_ = _tmp3_[0];
	_tmp5_ = sdx_graphics_sprite_SetCentered (_tmp4_, FALSE);
	_tmp6_ = _tmp5_;
	_sdx_graphics_sprite_release0 (_tmp6_);
	_tmp7_ = ((SdxUiComponent*) self)->bounds;
	_tmp8_ = ((SdxUiComponent*) self)->image;
	_tmp8__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp9_ = _tmp8_[0];
	_tmp10_ = _tmp9_->width;
	(*_tmp7_).w = (guint) _tmp10_;
	_tmp11_ = ((SdxUiComponent*) self)->bounds;
	_tmp12_ = ((SdxUiComponent*) self)->image;
	_tmp12__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp13_ = _tmp12_[0];
	_tmp14_ = _tmp13_->height;
	(*_tmp11_).h = (guint) _tmp14_;
	return self;
}


SdxUiLabel* sdx_ui_label_new (void) {
	SdxUiLabel* self;
	self = (SdxUiLabel*) sdx_ui_component_new (0, 0, 0, 0);
	((SdxUiComponent*) self)->kind = SDX_UI_COMPONENT_KIND_Label;
	return self;
}


static gpointer _sdx_font_retain0 (gpointer self) {
	return self ? sdx_font_retain (self) : NULL;
}


static SDL_Color* _sdl_video_color_dup (SDL_Color* self) {
	SDL_Color* dup;
	dup = g_new0 (SDL_Color, 1);
	memcpy (dup, self, sizeof (SDL_Color));
	return dup;
}


static gpointer __sdl_video_color_dup0 (gpointer self) {
	return self ? _sdl_video_color_dup (self) : NULL;
}


SdxUiLabelText* sdx_ui_label_text_new (const gchar* text, SdxFont* font, SDL_Color fg, SDL_Color* bg) {
	SdxUiLabelText* self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	SdxFont* _tmp2_;
	SdxFont* _tmp3_;
	SDL_Color _tmp4_;
	SDL_Color* _tmp5_;
	SDL_Color* _tmp6_;
	SDL_Color* _tmp7_;
	const gchar* _tmp8_;
	SdxFont* _tmp9_;
	SDL_Color* _tmp10_;
	SDL_Color* _tmp11_;
	SdxGraphicsSpriteTextSprite* _tmp12_;
	SdxGraphicsSprite** _tmp13_;
	SdxGraphicsSprite** _tmp14_;
	gint _tmp14__length1;
	SdxGraphicsSprite* _tmp15_;
	SdxGraphicsSprite* _tmp16_;
	SdxGraphicsSprite* _tmp17_;
	SDL_Rect* _tmp18_;
	SdxGraphicsSprite** _tmp19_;
	gint _tmp19__length1;
	SdxGraphicsSprite* _tmp20_;
	gint _tmp21_;
	SDL_Rect* _tmp22_;
	SdxGraphicsSprite** _tmp23_;
	gint _tmp23__length1;
	SdxGraphicsSprite* _tmp24_;
	gint _tmp25_;
	g_return_val_if_fail (text != NULL, NULL);
	g_return_val_if_fail (font != NULL, NULL);
	self = (SdxUiLabelText*) sdx_ui_label_new ();
	_tmp0_ = text;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (((SdxUiComponent*) self)->text);
	((SdxUiComponent*) self)->text = _tmp1_;
	_tmp2_ = font;
	_tmp3_ = _sdx_font_retain0 (_tmp2_);
	_sdx_font_release0 (((SdxUiComponent*) self)->font);
	((SdxUiComponent*) self)->font = _tmp3_;
	_tmp4_ = fg;
	_tmp5_ = __sdl_video_color_dup0 (&_tmp4_);
	_g_free0 (((SdxUiComponent*) self)->foreground);
	((SdxUiComponent*) self)->foreground = _tmp5_;
	_tmp6_ = bg;
	_tmp7_ = __sdl_video_color_dup0 (_tmp6_);
	_g_free0 (((SdxUiComponent*) self)->background);
	((SdxUiComponent*) self)->background = _tmp7_;
	_tmp8_ = ((SdxUiComponent*) self)->text;
	_tmp9_ = ((SdxUiComponent*) self)->font;
	_tmp10_ = ((SdxUiComponent*) self)->foreground;
	_tmp11_ = ((SdxUiComponent*) self)->background;
	_tmp12_ = sdx_graphics_sprite_text_sprite_new (_tmp8_, _tmp9_, *_tmp10_, _tmp11_);
	_tmp13_ = g_new0 (SdxGraphicsSprite*, 1 + 1);
	_tmp13_[0] = (SdxGraphicsSprite*) _tmp12_;
	((SdxUiComponent*) self)->image = (_vala_array_free (((SdxUiComponent*) self)->image, ((SdxUiComponent*) self)->image_length1, (GDestroyNotify) sdx_graphics_sprite_release), NULL);
	((SdxUiComponent*) self)->image = _tmp13_;
	((SdxUiComponent*) self)->image_length1 = 1;
	_tmp14_ = ((SdxUiComponent*) self)->image;
	_tmp14__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp15_ = _tmp14_[0];
	_tmp16_ = sdx_graphics_sprite_SetCentered (_tmp15_, FALSE);
	_tmp17_ = _tmp16_;
	_sdx_graphics_sprite_release0 (_tmp17_);
	_tmp18_ = ((SdxUiComponent*) self)->bounds;
	_tmp19_ = ((SdxUiComponent*) self)->image;
	_tmp19__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp20_ = _tmp19_[0];
	_tmp21_ = _tmp20_->width;
	(*_tmp18_).w = (guint) _tmp21_;
	_tmp22_ = ((SdxUiComponent*) self)->bounds;
	_tmp23_ = ((SdxUiComponent*) self)->image;
	_tmp23__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp24_ = _tmp23_[0];
	_tmp25_ = _tmp24_->height;
	(*_tmp22_).h = (guint) _tmp25_;
	return self;
}


SdxUiLabelNinePatch* sdx_ui_label_nine_patch_new (const gchar* text, SdxFont* font, SDL_Color fg, SdxGraphicsNinePatch* bg) {
	SdxUiLabelNinePatch* self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	SdxFont* _tmp2_;
	SdxFont* _tmp3_;
	SDL_Color _tmp4_;
	SDL_Color* _tmp5_;
	SdxGraphicsNinePatch* _tmp6_;
	const gchar* _tmp7_;
	SdxFont* _tmp8_;
	SDL_Color* _tmp9_;
	SdxGraphicsSpriteUISprite* _tmp10_;
	SdxGraphicsSprite** _tmp11_;
	SdxGraphicsSprite** _tmp12_;
	gint _tmp12__length1;
	SdxGraphicsSprite* _tmp13_;
	SdxGraphicsSprite* _tmp14_;
	SdxGraphicsSprite* _tmp15_;
	SDL_Rect* _tmp16_;
	SdxGraphicsSprite** _tmp17_;
	gint _tmp17__length1;
	SdxGraphicsSprite* _tmp18_;
	gint _tmp19_;
	SDL_Rect* _tmp20_;
	SdxGraphicsSprite** _tmp21_;
	gint _tmp21__length1;
	SdxGraphicsSprite* _tmp22_;
	gint _tmp23_;
	g_return_val_if_fail (text != NULL, NULL);
	g_return_val_if_fail (font != NULL, NULL);
	g_return_val_if_fail (bg != NULL, NULL);
	self = (SdxUiLabelNinePatch*) sdx_ui_label_new ();
	_tmp0_ = text;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (((SdxUiComponent*) self)->text);
	((SdxUiComponent*) self)->text = _tmp1_;
	_tmp2_ = font;
	_tmp3_ = _sdx_font_retain0 (_tmp2_);
	_sdx_font_release0 (((SdxUiComponent*) self)->font);
	((SdxUiComponent*) self)->font = _tmp3_;
	_tmp4_ = fg;
	_tmp5_ = __sdl_video_color_dup0 (&_tmp4_);
	_g_free0 (((SdxUiComponent*) self)->foreground);
	((SdxUiComponent*) self)->foreground = _tmp5_;
	_tmp6_ = bg;
	_tmp7_ = ((SdxUiComponent*) self)->text;
	_tmp8_ = ((SdxUiComponent*) self)->font;
	_tmp9_ = ((SdxUiComponent*) self)->foreground;
	_tmp10_ = sdx_graphics_sprite_ui_sprite_new (_tmp6_, _tmp7_, _tmp8_, *_tmp9_, 100, 40);
	_tmp11_ = g_new0 (SdxGraphicsSprite*, 1 + 1);
	_tmp11_[0] = (SdxGraphicsSprite*) _tmp10_;
	((SdxUiComponent*) self)->image = (_vala_array_free (((SdxUiComponent*) self)->image, ((SdxUiComponent*) self)->image_length1, (GDestroyNotify) sdx_graphics_sprite_release), NULL);
	((SdxUiComponent*) self)->image = _tmp11_;
	((SdxUiComponent*) self)->image_length1 = 1;
	_tmp12_ = ((SdxUiComponent*) self)->image;
	_tmp12__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp13_ = _tmp12_[0];
	_tmp14_ = sdx_graphics_sprite_SetCentered (_tmp13_, FALSE);
	_tmp15_ = _tmp14_;
	_sdx_graphics_sprite_release0 (_tmp15_);
	_tmp16_ = ((SdxUiComponent*) self)->bounds;
	_tmp17_ = ((SdxUiComponent*) self)->image;
	_tmp17__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp18_ = _tmp17_[0];
	_tmp19_ = _tmp18_->width;
	(*_tmp16_).w = (guint) _tmp19_;
	_tmp20_ = ((SdxUiComponent*) self)->bounds;
	_tmp21_ = ((SdxUiComponent*) self)->image;
	_tmp21__length1 = ((SdxUiComponent*) self)->image_length1;
	_tmp22_ = _tmp21_[0];
	_tmp23_ = _tmp22_->height;
	(*_tmp20_).h = (guint) _tmp23_;
	return self;
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




