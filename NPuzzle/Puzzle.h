#pragma once

#include "Common.h"
#include "Node.h"
#include "SearchMethod.h"

class Puzzle
{
private:
	State* m_GoalState;
	State* m_State;
	byte m_Width, m_Height;
public:
	Puzzle(byte width, byte height);
	~Puzzle();

	void SetCurrentState(const String& state);
	void SetGoalState(const String& state);

	int FindBlankTile() const;
	std::vector<Direction> Solve(SearchMethod& method);

	inline State* GetState() const { return m_State; }
	inline State* GetGoalState() const { return m_GoalState; }

	inline byte GetWidth() const { return m_Width; }
	inline byte GetHeight() const { return m_Height; }
};