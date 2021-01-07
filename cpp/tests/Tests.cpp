#include "report/ReportGenerator.h"

#include <domain/book/Author.h>
#include <domain/book/Novel.h>
#include <domain/country/Country.h>
#include <domain/country/Currency.h>
#include <domain/country/Language.h>
#include <purchase/Invoice.h>
#include <purchase/PurchasedBook.h>

#include "gtest/gtest.h"

#include <memory>

TEST(Invoice, taxes_are_applied_correctly)
{
   purchase::Invoice invoice(
      "Murex",
      domain::country::Country(
         "Lebanon",
         domain::country::Currency::US_DOLLAR, 
         domain::country::Language::ARABIC
      )
   );

   const double price = 42.;
	
   invoice.addPurchasedBook(
      std::make_shared<purchase::PurchasedBook>(
         std::make_shared<domain::book::Novel>(
            "Des Milliards de Tapis de Cheveux",
            price,
            domain::book::Author(
               "Andreas Eschbach", 
               domain::country::Country(
                  "Germany",
                  domain::country::Currency::EURO,
                  domain::country::Language::GERMAN
               )
            ),
            domain::country::Language::FRENCH,
            std::vector<domain::book::Genre>{ domain::book::Genre::ADVENTURE_FICTION }
         ),
      1));

   double totalAmount = invoice.computeTotalAmount();
   EXPECT_LT(price, totalAmount);
}
