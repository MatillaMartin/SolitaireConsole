#include "CardStack.h"

#include "Card.h"

namespace panda
{
	CardStack::CardStack(std::vector<Card>&& cards)
		: m_cards(cards)
	{
	}

	std::optional<CardStack> CardStack::take(int index)
	{
		if (index >= m_cards.size())
			return {};

		auto first = m_cards.begin();
		std::advance(first, index);
		return std::vector<Card>(first, m_cards.end());
	}

	std::optional<CardStack> CardStack::takeTop()
	{
		if (m_cards.empty())
			return {};

		return take(static_cast<int>(m_cards.size()) - 1);
	}

	std::optional<Card> CardStack::top() const
	{
		if (m_cards.empty())
			return {};

		return m_cards.back();
	}

	const std::vector<Card>& CardStack::cards() const { return m_cards; }

	bool CardStack::append(CardStack&& stack)
	{
		m_cards.insert(m_cards.end(), std::make_move_iterator(stack.m_cards.begin()), std::make_move_iterator(stack.m_cards.end()));
		return true;
	}

	void CardStack::flipAll()
	{
		for (auto& card : m_cards)
			card.flip();
	}

	void CardStack::flipTop()
	{
		if (m_cards.empty())
			return;

		m_cards.back().flip();
	}

	int CardStack::size() { return static_cast<int>(m_cards.size()); }
}