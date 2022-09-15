#pragma once
#include "Card.h"

#include <optional>
#include <vector>

namespace panda
{
	class CardStack
	{
	public:
		CardStack(std::vector<Card>&& cards);

		// Takes all cards after index, including index
		// Returns empty optional if no cards can be taken
		std::optional<CardStack> take(int index);

		// Takes top card of stack
		// Returns empty optional if no cards can be taken
		std::optional<CardStack> takeTop();

		// Returns the card at the top
		std::optional<Card> top() const;

		// Returns all the cards in the stack
		const std::vector<Card>& cards() const;

		// Appends stack at the end of the current stack
		// Returns false if operation fails
		bool append(CardStack&& stack);

		// Inverts the order of the stack
		void invertOrder();

		// Flips all cards in the stack
		void flipAll();

		// Flips the top card in the stack
		void flipTop();

		// Number of cards in stack
		int size() const;

	private:
		std::vector<Card> m_cards;
	};
}