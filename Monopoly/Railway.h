#pragma once
class Railway : public Property
{
private:
	static const int amountProperty;
	static const int identificator;
public:
	Railway() = default;
	Railway(const string& name, const int colour,
		const int price, const int collateralValue,
		const int* rent);
	Railway(const Railway& property) = delete;
	Railway(Railway&& railwayStation) = delete;

	virtual void SetRent(const int* rent) override;
	virtual void BuildHouse() override {};
	virtual void DestroyHouse() override {};
	virtual int GetAmountHouses() const override { return 0; };
	virtual void ResetAmountOfHouses() override {};
	virtual int GetAmountProperties() const override;
	virtual int GetIdentificator() const override;

	const Railway* operator = (const Railway& railwayStation) = delete;
	const Railway* operator = (Railway&& railwayStation) = delete;
};

