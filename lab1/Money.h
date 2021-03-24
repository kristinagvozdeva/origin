class Money
{
public:
	Money();
	Money(const long rubles, const unsigned char cents; ) ;
	Money(const Money& other) ;
	~Money();



	/**
	 * \brief  метод, возвращающий значение рублей
	 * \return рубли
	 */
	long GetRubles() const ;



	/**
	 * \brief  метод, возвращающий центы
	 * \return центы
	 */
	unsigned char GetCents() const ;


	/**
	 * \brief  метод, возвращающий сложение сумм
	 * \return сложение сумм
	 */
	Money& GetSumm(const Money& other) const ;


	/**
	 * \brief  метод, возвращающий вычитаниесумм
	 * \return вычитание сумм
	 */
	Money& GetSub(const Money& other) const ;


	/**
	 * \brief  метод, деления сумм
	 */
	Money& DivisionSumm(const Money& other) const ;


	/**
	 * \brief  метод, позволяющий провести деление суммы на дробное число 
	 */
	Money& DivisionSummFraction(const Money& other) const ;


	/**
	 * \brief  метод, позволяющий провести умножение суммы на дробное число 
	 */
	Money& MultiplicationFraction(const Money& other) const ;


	/**
	 * \brief  метод, позволяющий провести сравнение сумм
	 * \return результат сравнения 
	 */
	bool AreEqual(const Money& other) const ;

private:

	long rubles;

	unsigned char cents;
}

