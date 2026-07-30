use mamata_classicmodels;
select p.*,'Mamata' as 'Preparedby'from products p
where productLine= 'Classic Cars'

select productName,buyPrice, MSRP  ,'Mamata' as 'Preparedby'from products 
where buyPrice > 80;

select  productCode ,productName ,'Mamata' as 'Preparedby' from products 
where quantityInStock <500 

select * from products
select productName,productScale as 'Scale',productVendor as 'Vendor','Mamata' as 'Preparedby' from products
where productVendor like '%Diecast%' ;

select productName, (MSRP -buyPrice ) as profitMargin,'Mamata' as 'Preparedby'   from products 
where MSRP>150

select *from employees

select firstName, lastName,jobTitle,'Mamata' as 'Preparedby'  from employees
where jobTitle ='Sales Rep';

select firstName,lastName,email,'Mamata' as 'Preparedby'   from employees
where officeCode=4

select employeeNumber,firstName,lastName,'Mamata' as 'Preparedby'   from employees
where reportsTo  is NULL

select firstName,lastName,jobTitle, 'Mamata' as 'Preparedby' from employees   where
jobTitle like '%Manager%'

select employeeNumber,email,'Mamata' as 'Preparedby' from employees  
where email like '%@classicmodelcars.com'

select *from customers

select customerName as 'Name' ,country ,'Mamata' as 'Preparedby' from customers where
country='France'

select customerName,creditLimit ,'Mamata' as 'Preparedby' from customers
 where creditLimit > 100000
 
 select customerName,city,phone ,'Mamata' as 'Preparedby' from customers
 where city like 'San%'
 
 select customerNumber,customerName,'Mamata' as 'Preparedby' from customers
where salesRepEmployeeNumber is Null

select customername,country,creditLimit,'Mamata' as 'Preparedby' from customers
where creditLimit between 50000 and 100000