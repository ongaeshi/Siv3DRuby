
#include <Siv3D.hpp>
#include "mruby.h"
#include "mruby/irep.h"
#include "mruby/compile.h"
#include "mruby/string.h"

void Main()
{
	mrb_state* mrb = mrb_open();
	//mrb_init(mrb);

	const Font font(30);

	while (System::Update())
	{
		font(L"ようこそ、Siv3D の世界へ！").draw();

		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}
