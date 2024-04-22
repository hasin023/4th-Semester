// Creating Nodes
// 1. Customers
create (john:CUSTOMER { customer_id:102 , name: 'John', phone_no: 1234567890, age: 30, gender: 'Male', country: 'USA' })
RETURN john

create (alice:CUSTOMER { customer_id:123 , name: 'Alice', phone_no: 9876543210, age: 20, gender: 'Female', country: 'UK' })
RETURN alice

create (bob:CUSTOMER { customer_id:311 , name: 'Bob', phone_no: 5555555555, age: 40, gender: 'Male', country: 'Canada' })
RETURN bob

// 2. Authors
create (rowling:AUTHOR { author_name: 'J.K. Rowling', country: 'UK' })

// 3. Books
create (philosopher_stone:BOOK { isbn: '1408855652', title: 'Harry Potter and the Philosophers Stone', genre: 'Fantasy', published_year: 1997, price: 9.99 })

create (chamber_secrets:BOOK { isbn: '0439064866', title: 'Harry Potter and the Chamber of Secrets', genre: 'Fantasy', published_year: 1998, price: 10.99 })

// Creating Relationships
// 1. WROTE
MATCH (rowling:AUTHOR { author_name: 'J.K. Rowling' }), (philosopher_stone:BOOK { isbn: '1408855652' })
create (rowling)-[rel:WROTE]->(philosopher_stone)
RETURN rowling, philosopher_stone

MATCH (rowling:AUTHOR { author_name: 'J.K. Rowling' }), (chamber_secrets:BOOK { isbn: '0439064866' })
create (rowling)-[rel:WROTE]->(chamber_secrets)
RETURN rowling, chamber_secrets

// 2. Create book with author
create (st_king:AUTHOR { author_name: 'Stephen King', country: 'USA' })-[rel:WROTE]->(the_shining:BOOK { isbn: '1982102319', title: 'The Shining', genre: 'Horror', published_year: 1977, price: 12.99 })

create (ag_chris:AUTHOR { author_name: 'Agatha Christie', country: 'UK' })-[rel:WROTE]->(the_shining:BOOK { isbn: '0062073492', title: 'Murder on the Orient Express', genre: 'Mystery', published_year: 1934, price: 8.99 })

// 3. PURCHASED
MATCH (customer:CUSTOMER { customer_id:123 }), (book:BOOK {isbn: '1408855652'})
create (customer)-[rel:PURCHASED { amount:3 }]->(book)
RETURN customer, book

MATCH (customer:CUSTOMER { customer_id:123 }), (book:BOOK {isbn: '0439064866'})
create (customer)-[rel:PURCHASED { amount:1 }]->(book)
RETURN customer, book

MATCH (customer:CUSTOMER { customer_id:311 }), (book:BOOK {isbn: '0062073492'})
create (customer)-[rel:PURCHASED { amount:1 }]->(book)
RETURN customer, book

MATCH (customer:CUSTOMER { customer_id:102 }), (book:BOOK {isbn: '0062073492'})
create (customer)-[rel:PURCHASED { amount:1 }]->(book)
RETURN customer, book

// 4. RATED
MATCH (rater: CUSTOMER { customer_id: 123 }), (book:BOOK {isbn: '1408855652'})
create (rater)-[rel:RATED { rating: 5, rating_date: date('2021-02-11') }]->(book)
RETURN rater, book

MATCH (rater: CUSTOMER { customer_id: 311 }), (book:BOOK {isbn: '1408855652'})
create (rater)-[rel:RATED { rating: 3, rating_date: date('2022-04-19') }]->(book)
RETURN rater, book

MATCH (rater: CUSTOMER { customer_id: 311 }), (book:BOOK {isbn: '0062073492'})
create (rater)-[rel:RATED { rating: 4, rating_date: date('2024-01-09') }]->(book)
RETURN rater, book

MATCH (rater: CUSTOMER { customer_id: 102 }), (book:BOOK {isbn: '0062073492'})
create (rater)-[rel:RATED { rating: 5, rating_date: date('2023-04-04') }]->(book)
RETURN rater, book

// Get book by author name
MATCH (rater: CUSTOMER { customer_id: 123 })
MATCH (author:AUTHOR)-[wrote:WROTE]->(book:BOOK)
WHERE author.author_name = 'J.K. Rowling'
create (rater)-[rated:RATED { rating: 5, rating_date: date('2021-03-12') }]->(book)
RETURN rater, book

MATCH (rater: CUSTOMER { customer_id: 123 })
MATCH (author:AUTHOR)-[wrote:WROTE]->(book:BOOK)
WHERE author.author_name = 'Stephen King'
create (rater)-[rated:RATED { rating: 2, rating_date: date('2023-03-18') }]->(book)
RETURN rater, book

// FOLLOWS
MATCH (cus1:CUSTOMER { customer_id: 123 }), (cus2:CUSTOMER { customer_id: 311 })
create (cus1)-[rel:FOLLOWS]->(cus2)
RETURN cus1, cus2

MATCH (cus1:CUSTOMER { customer_id: 311 }), (cus2:CUSTOMER { customer_id: 123 })
create (cus1)-[rel:FOLLOWS]->(cus2)
RETURN cus1, cus2

MATCH (cus1:CUSTOMER { customer_id: 311 }), (cus2:CUSTOMER { customer_id: 102 })
create (cus1)-[rel:FOLLOWS]->(cus2)
RETURN cus1, cus2

MATCH (customer:CUSTOMER { customer_id: 123 }), (author:AUTHOR { author_name: 'J.K. Rowling' })
create (customer)-[rel:FOLLOWS]->(author)
RETURN customer, author

MATCH (customer:CUSTOMER { customer_id: 311 }), (author:AUTHOR { author_name: 'Agatha Christie' })
create (customer)-[rel:FOLLOWS]->(author)
RETURN customer, author

MATCH (customer:CUSTOMER { customer_id: 102 }), (author:AUTHOR { author_name: 'Agatha Christie' })
create (customer)-[rel:FOLLOWS]->(author)
RETURN customer, author

// 9. Make a dump

// 10 -> Query
// a ->
MATCH (customer: CUSTOMER)-[rated:RATED]->(book:BOOK)
RETURN customer, rated, book
// b ->
MATCH ()-[rel:FOLLOWS]->()
RETURN rel
