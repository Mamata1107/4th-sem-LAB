USE mamata_classicmodels;

SELECT c.customerName,e.firstName,e.lastName,"Mamata" as "Prepared by"
FROM customers c
JOIN employees e
ON c.salesRepEmployeeNumber = e.employeeNumber;

select *from orders
select o.*,c.customerName,o.orderDate,"Mamata" as "Prepared by"
from customers c
join orders o
on c.customerNumber=o.customerNumber

select * from products
select * from productlines
select p.productName,pl.textdescription,"Mamata" as "Prepared by"
from products p
join productlines pl
on p.productline=pl.productline

select * from employees
select * from offices
select e.firstname,e.lastname,o.city,o.state,o.country,"Mamata" as "Prepared by"
from employees e
join offices o
on e.officeCode=o.officeCode

select *from payments
select * from customers
select p.*,c.customerName,"Mamata" as "Prepared by"
from payments p
join customers c
on p.customerNumber=c.customerNumber

select *from orders
select *from orderdetails
select