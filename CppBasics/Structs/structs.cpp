// Example Struct
struct EmployeeRecord {
    // Typedefs
    using ID = int;
    using name = std::string;

    ID employeeID; // Employee ID
    name employeeName; // Employee Name

    // Enumeration for the department names
    enum Department = {
        HR,
        Engineering, 
        Marketing, 
        Sales,
        Administration
    };

    Department departmentName; // Employee's Department

    float employeeSalary; // Employee's Salary
};