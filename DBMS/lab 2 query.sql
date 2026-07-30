use mamata_classicmodels;

select *from products
select *, 'Mamata' as 'Preparedby' from products
where productline='Classic Cars' and MSRP>150;

select ProductName,productVendor, 'Mamata' as 'Preparedby' from products
where productline='Motorcycles' or buyPrice<30;

select *, 'Mamata' as 'Preparedby' from products
where quantityInStock>5000 and  MSRP<100;

select ProductName,productVendor, 'Mamata' as 'Preparedby' from products
where productline<>'Ships' and buyPrice>60;

select ProductName, 'Mamata' as 'Preparedby' from products
where productScale='1:18' and  quantityInStock between 1000 and 3000;

select *from employees;
select *,'Mamata' as 'Preparedby' from employees
where officeCode=1 and jobTitle ='Sales Rep';

select *,'Mamata' as 'Preparedby' from employees
where reportsTo=1056 and jobTitle like '%Manager%';

select firstName,lastName,email,'Mamata' as 'Preparedby' from employees
where officeCode=4 or officeCode= 6;

select *,'Mamata' as 'Preparedby' from employees
where jobTitle <>'Sales Rep' and (reportsTo <> 1143 or reportsTo  is Null) ;

select *,'Mamata' as 'Preparedby' from employees
where officeCode=2 and firstName like 'S%';

select *,'Mamata' as 'Preparedby' from customers;
select *,'Mamata' as 'Preparedby' from customers
where country ='USA' and creditLimit >100000;

select *,'Mamata' as 'Preparedby' from customers
where salesRepEmployeeNumber is NULL and country <>'USA';

select *,'Mamata' as 'Preparedby' from customers
where (country ='France' or country ='Germany') and creditLimit <70000 ;

select customerName,'Mamata' as 'Preparedby' from customers
where city ='San Francisco' and postalCode is not Null;

select *,'Mamata' as 'Preparedby' from customers
where (state ='NY' or state ='CA') and creditLimit between 50000 and 100000; 
where (country ='France' or country ='Germany') and creditLimit <70000 ;