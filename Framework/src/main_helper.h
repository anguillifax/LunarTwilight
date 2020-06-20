#pragma once

#include "input/InputSystem.h"

namespace nova {
	
	class LoadInputs {
		InputSystem* inputs;

		void load();

	public:
		explicit LoadInputs(InputSystem* inputs)
			: inputs(inputs)
		{
			load();
		}
	};

} // namespace nova
