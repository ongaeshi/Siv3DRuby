#pragma once

#include <Siv3D.hpp>
#include "mruby.h"

//----------------------------------------------------------
namespace siv3druby {
    class MrbDrawableString {
    public:
        static void Init(mrb_state *mrb);
        static mrb_value ToMrb(mrb_state *mrb, DrawableString *ptr);
        static mrb_value ToMrb(mrb_state *mrb, struct RClass *cc, DrawableString *ptr);
        static DrawableString* ToCpp(mrb_state *mrb, mrb_value value);
        static DrawableString* ToCpp(mrb_state *mrb, struct RClass *cc, mrb_value value);
    };
}
