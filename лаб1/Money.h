class Money
{
public:
	Money() {};
	Money(const long rubles, const unsigned char cents; ) {};
	Money(const Money& other) {};
	~Money();



	/**
	 * \brief  ћетод, возвращающий значение рублей
	 * \return рубли
	 */
	long GetRubles() const {};



	/**
	 * \brief  ћетод, возвращающий центы
	 * \return центы
	 */
	unsigned char GetCents() const {};


	/**
	 * \brief  ћетод, возвращающий сложение сумм
	 * \return сложение сумм
	 */
	Money& GetSumm(const Money& other) const {};


	/**
	 * \brief  ћетод, возвращающий вычитаниесумм
	 * \return ¬ычитание сумм
	 */
	Money& GetSub(const Money& other) const {};


	/**
	 * \brief  ћетод, возвращающий деленние сумм
	 * \return деление сумм
	 */
	Money& DivisionSumm(const Money& other) const {};


	/**
	 * \brief  ћетод, позвол¤ющий провести деление суммы на дробное число 
	 * \return результат
	 */
	Money& DivisionSummFraction(const Money& other) const {};


	/**
	 * \brief  ћетод, позвол¤ющий провести умножение суммы на дробное число 
	 * \return результат
	 */
	Money& MultiplicationFraction(const Money& other) const {};


	/**
	 * \brief  ћетод, позвол¤ющий провести сравнение сумм
	 * \return результат
	 */
	bool AreEqual(const Money& other) const {};

private:

	long rubles;

	unsigned char cents;
}

