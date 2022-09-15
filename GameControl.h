#pragma once

#include "GameAction.h"

#include <utility>
#include <optional>

namespace panda
{
	class CardStack;
	class GameLayout;
	class Game;

	class GameControl
	{
	public:
		enum class State
		{
			Select,
			Move
		};

		GameControl(Game & game, GameLayout& layout);

		void action(GameAction action);

		int stackIndex() const;
		int cardIndex() const;

	private:
		const CardStack& stack();

		Game& m_game;
		const GameLayout& m_layout;
		int m_cardIndex = 0;
		int m_stackIndex = 0;

		State m_state = State::Select;
		int m_markedCardIndex = 0;
		int m_markedStackIndex = 0;
	};
}