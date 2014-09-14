// Cheat notes updated 4 12 2014


#include "stdafx.h"

// If you have stdafx / recompiled header, any other includes not in the stdafx.h file will confuse the compiler


//Likely always want me
using namespace std;
using namespace QuantLib;


int _tmain(int argc, _TCHAR* argv[])
{
	// Utility
		
	//#include <ql/quantlib.hpp>
	// You'll need the above in waht ever .h you use
	// Also D:\My Documents\My Professional\My Programming\C++\C++ Libraries\QuantLib\QuantLib-1.4; in your includes path
	// Also D:\My Documents\My Professional\My Programming\C++\C++ Libraries\Boost\boost_1_55_0_32; in your includes path
	// Also D:\My Documents\My Professional\My Programming\C++\C++ Libraries\Boost\boost_1_55_0_32\lib32-msvc-12.0; in your library path
	// Also D:\My Documents\My Professional\My Programming\C++\C++ Libraries\QuantLib\QuantLib-1.4\lib; in your library path

	// Market Data Hierachy
	// Practice appears to be to load data in at three differenet levels
	// Rates, Quotes and Rate Helpers

	// Rates 
	// Pure data. Would normally be skiped and read off DB

	Rate s8yQuote = 0.023143;
	
	// Quotes
	// The object intended to store data. Can be repointed to other sources of data without screwing up dependent objects
	// Also quote is an observable which means it can provide easy updates
	
	boost::shared_ptr<Quote> s7yRate(new SimpleQuote(s7yQuote));


	// RateHelper
	// Actually allows you to interepret what the data means and what its conventions are.
	
	boost::shared_ptr<RateHelper> s5y(new SwapRateHelper(
		Handle<Quote>(s5yRate), 5 * Years,
		calendar, swFixedLegFrequency,
		swFixedLegConvention, swFixedLegDayCounter,
		swFloatingLegIndex));
	
	//Date functions

	Calendar calendar = TARGET();
	Date settlementDate(22, September, 2004);
	// must be a business day
	settlementDate = calendar.adjust(settlementDate);
	Settings::instance().evaluationDate() = todaysDate;
	Date todaysDate = calendar.advance(settlementDate, -fixingDays, Days);



	//Building YCs
	// YCs are built up from bringing togethor simpler objects
	// The long proper version takes a rate object, which can be used to build a quot object, which can be used to build a rate helper, which gets pushed onto a vector list, that gets passed into a YC builder:
	// But you can just do it with DF and its easier


	// swaps
	Rate s2yQuote = 0.037125;
	boost::shared_ptr<Quote> s2yRate(new SimpleQuote(s2yQuote));

	// setup swaps
	Frequency swFixedLegFrequency = Annual;
	BusinessDayConvention swFixedLegConvention = Unadjusted;
	DayCounter swFixedLegDayCounter = Thirty360(Thirty360::European);
	boost::shared_ptr<IborIndex> swFloatingLegIndex(new Euribor6M);

	boost::shared_ptr<RateHelper> s2y(new SwapRateHelper(
		Handle<Quote>(s2yRate), 2 * Years,
		calendar, swFixedLegFrequency,
		swFixedLegConvention, swFixedLegDayCounter,
		swFloatingLegIndex));


	// A depo-futures-swap curve
	std::vector<boost::shared_ptr<RateHelper> > depoFutSwapInstruments;
	depoFutSwapInstruments.push_back(d1w);
	depoFutSwapInstruments.push_back(d1m);
	depoFutSwapInstruments.push_back(fut1);
	depoFutSwapInstruments.push_back(fut2);
	depoFutSwapInstruments.push_back(fut3);
	depoFutSwapInstruments.push_back(fut4);
	depoFutSwapInstruments.push_back(fut5);
	depoFutSwapInstruments.push_back(fut6);
	depoFutSwapInstruments.push_back(fut7);
	depoFutSwapInstruments.push_back(fut8);
	depoFutSwapInstruments.push_back(s3y);
	depoFutSwapInstruments.push_back(s5y);
	depoFutSwapInstruments.push_back(s10y);
	depoFutSwapInstruments.push_back(s15y);
	boost::shared_ptr<YieldTermStructure> depoFutSwapTermStructure(
		new PiecewiseYieldCurve<Discount, LogLinear>(
		settlementDate, depoFutSwapInstruments,
		termStructureDayCounter,
		tolerance));



	// Term structures that will be used for pricing:
	// the one used for discounting cash flows
	RelinkableHandle<YieldTermStructure> discountingTermStructure;
	// the one used for forward rate forecasting
	RelinkableHandle<YieldTermStructure> forecastingTermStructure;


	// Easier YC builds

	Date settlement = cal.advance(today, settlementDays, Days);
	
	dates.push_back(settlement); dates.push_back(settlement + 1 * Days);
	dates.push_back(settlement + 1 * Weeks); dates.push_back(settlement + 1 * Months);
	dates.push_back(settlement + 2 * Months); dates.push_back(settlement + 3 * Months);
	dates.push_back(settlement + 6 * Months); dates.push_back(settlement + 9 * Months);
	dates.push_back(settlement + 1 * Years); dates.push_back(settlement + 1 * Years + 3 * Months);
	dates.push_back(settlement + 1 * Years + 6 * Months); dates.push_back(settlement + 1 * Years + 9 * Months);
	dates.push_back(settlement + 2 * Years);
	
	dfs.push_back(1.0); dfs.push_back(0.9999656);
	dfs.push_back(0.9999072); dfs.push_back(0.9996074);
	dfs.push_back(0.9990040); dfs.push_back(0.9981237);
	dfs.push_back(0.9951358); dfs.push_back(0.9929456);
	dfs.push_back(0.9899849); dfs.push_back(0.9861596); //
	dfs.push_back(0.9815178); dfs.push_back(0.9752363);
	dfs.push_back(0.9680804);
	
	Date tmpDate1 = settlement + 1 * Years + 3 * Months;
	
	InterpolatedDiscountCurve <LogLinear > curve(dates, dfs, dc, cal);
	
	std::cout << "Zero Rate: " << curve.zeroRate(tmpDate1, dc, Simple, Annual) << std::endl;
	std::cout << "Discount: " << curve.discount(tmpDate1) << std::endl;





	// Common QL data objects that are worth learning


	// Term structure
	// Use to hold yield curves
	Handle<YieldTermStructure> rhTermStructure(
		boost::shared_ptr<FlatForward>(
		new FlatForward(settlementDate, Handle<Quote>(flatRate),
		Actual365Fixed())));


	// Business day convetion
	// Set once globally and forget
	BusinessDayConvention floatingLegConvention = ModifiedFollowing;

	// Day Counter
	// Set once globally and forget
	DayCounter fixedLegDayCounter = Thirty360(Thirty360::European);

	// Frequency
	// Set once globally and forget
	Frequency floatingLegFrequency = Semiannual;

	// Index object for swaps
	// Can be a bit tricky as you might need to set it up before your YC creation to take in swap objects to build your YC
	boost::shared_ptr<IborIndex> indexSixMonths(new
		Euribor6M(rhTermStructure));


	// Cash flow schedules but really just date scheduels so can also be used for exercise
	Schedule fixedSchedule(startDate, maturity, Period(fixedLegFrequency),
		calendar, fixedLegConvention, fixedLegConvention,
		DateGeneration::Forward, false);
	Schedule floatSchedule(startDate, maturity, Period(floatingLegFrequency),
		calendar, floatingLegConvention, floatingLegConvention,
		DateGeneration::Forward, false);

	Schedule Capschedule(CapStartDate, CapendDate, Period(Capfrequency), calendar,
		Capconvention, Capconvention,
		DateGeneration::Forward, false);


	// Swap
	// Swap object. Needs some date schedules
	boost::shared_ptr<VanillaSwap> swap(new VanillaSwap(
		type, 1000.0,
		fixedSchedule, dummyFixedRate, fixedLegDayCounter,
		floatSchedule, indexSixMonths, 0.0,
		indexSixMonths->dayCounter()));


	// Pricing engine. Instruments dont assume this. So can be tricky to set up
	swap->setPricingEngine(boost::shared_ptr<PricingEngine>(
		new DiscountingSwapEngine(rhTermStructure)));

	// One of the desgn patters (factory) used to make like easy
	SwaptionHelper(swaptionMaturities[i],
		Period(swapLenghts[j], Years),
		Handle<Quote>(vol),
		indexSixMonths,
		indexSixMonths->tenor(),
		indexSixMonths->dayCounter(),
		indexSixMonths->dayCounter(),
		rhTermStructure)


		// Models used for pricing
		// defining the models
		boost::shared_ptr<G2> modelG2(new G2(rhTermStructure));
	boost::shared_ptr<HullWhite> modelHW(new HullWhite(rhTermStructure));



	//Building CF schedule and swaps

	//Must set up 7y swap

	Integer RAlenghtInYears = 11;

	Date RAmaturity = settlementDate + RAlenghtInYears*Years;
	Schedule RAfixedSchedule(settlementDate, RAmaturity,
		Period(fixedLegFrequency),
		calendar, fixedLegConvention,
		fixedLegConvention,
		DateGeneration::Forward, false);
	Schedule RAfloatSchedule(settlementDate, RAmaturity,
		Period(floatingLegFrequency),
		calendar, floatingLegConvention,
		floatingLegConvention,
		DateGeneration::Forward, false);
	VanillaSwap RAspot11YearSwap(swapType, nominal,
		RAfixedSchedule, fixedRate, fixedLegDayCounter,
		RAfloatSchedule, euriborIndex, spread,
		floatingLegDayCounter);

	RAspot11YearSwap.setPricingEngine(swapEngine);
	fairRate = RAspot11YearSwap.fairRate();


	// How to query the YC

	//Imply out 7y swap rate
	//Must set up 7y swap

	Integer RAlenghtInYears = 11;

	Date RAmaturity = settlementDate + RAlenghtInYears*Years;
	Schedule RAfixedSchedule(settlementDate, RAmaturity,
		Period(fixedLegFrequency),
		calendar, fixedLegConvention,
		fixedLegConvention,
		DateGeneration::Forward, false);
	Schedule RAfloatSchedule(settlementDate, RAmaturity,
		Period(floatingLegFrequency),
		calendar, floatingLegConvention,
		floatingLegConvention,
		DateGeneration::Forward, false);
	VanillaSwap RAspot11YearSwap(swapType, nominal,
		RAfixedSchedule, fixedRate, fixedLegDayCounter,
		RAfloatSchedule, euriborIndex, spread,
		floatingLegDayCounter);

	RAspot11YearSwap.setPricingEngine(swapEngine);
	fairRate = RAspot11YearSwap.fairRate();


	std::cout << "RA Test pat swap rate 11Y " << separator;
	std::cout << std::setw(headers[3].size())
		<< io::rate(fairRate) << separator;
	std::cout << std::setw(headers[1].size())
		<< std::fixed << std::setprecision(4) << fairRate << separator;

	// 8y df
	QuantLib::Date newYearsEve(31, QuantLib::Dec, 2008);
	std::cout << std::endl;
	std::cout << "Discount: " << depoFRASwapTermStructure->discount(newYearsEve) << std::endl;


	// Forward rate
	Date datex(25, June, 2013);
	Period period(6 * Months);
	double forward6m = depoFRASwapTermStructure->forwardRate(datex, period, depoFRASwapTermStructure->dayCounter(), QuantLib::Compounding::Simple);
	std::cout << std::endl;
	std::cout << "Forward: " << forward6m << std::endl;


	std::cout << std::endl;
	std::cout << "Zero Rate: " << depoFRASwapTermStructure->zeroRate(datex, depoFRASwapTermStructure->dayCounter(), Simple, Annual) << std::endl;




}
