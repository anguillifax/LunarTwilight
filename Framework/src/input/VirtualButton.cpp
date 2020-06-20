#include "VirtualButton.h"

namespace nova {

	VirtualButton::VirtualButton(const std::initializer_list<RawButton*>& sub_button_list)
		: buttons(sub_button_list)
	{
	}

	/**
	* @brief Add a new button to the VirtualButton.
	*
	* If the button is already a part of this virtual button,
	* this function has no effect.
	*
	* @param button Button to add.
	*/
	void VirtualButton::add_sub_button(RawButton* button)
	{
		buttons.emplace(button);
	}

	void VirtualButton::update()
	{
		bool last_pressed = pressed;
		pressed = false;

		for (RawButton* button : buttons) {
			if (button->get_pressed()) {
				pressed = true;
				break;
			}
		}

		just_pressed = pressed && !last_pressed;
		just_released = !pressed && last_pressed;
	}

} // namespace nova
