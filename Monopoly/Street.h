#pragma once
class Street : public Property
{
private:
	int _amountHouse = 0;
public:
	Street() = default;
	Street(const string& name, const int colour,
		const int price, const int collateralValue,
		const int* rent, const int amountHouse);
	Street(const Street& street) = delete;
	Street(Street&& street) = delete;

	virtual void SetRent(const int* rent) override;
	virtual void LayDown() override;
	virtual void BuildHouse() override;
	virtual void DestroyHouse() override;
	virtual int GetAmountHouses() const override;
	Street* GetStreet();
	virtual int GetAmountProperties() const override;
	virtual int GetIdentificator() const override;
	void ResetAmountOfHouses() override;

	const Street* operator = (const Street& street) = delete;
	const Street* operator = (Street&& street) = delete;

	static const int amountProperty;
	static const int identificator;
};

