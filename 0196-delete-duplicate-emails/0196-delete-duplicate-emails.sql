# Write your MySQL query statement below
DELETE p2 FROM Person p2,
    Person p1
WHERE
    p1.Email = p2.Email AND p2.Id > p1.Id

