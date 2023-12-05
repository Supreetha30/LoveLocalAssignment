def majority_elements(nums):
    if not nums:
        return []

    candidate1, candidate2 = None, None
    count1, count2 = 0, 0

    for num in nums:
        if num == candidate1:
            count1 += 1
        elif num == candidate2:
            count2 += 1
        elif count1 == 0:
            candidate1, count1 = num, 1
        elif count2 == 0:
            candidate2, count2 = num, 1
        else:
            count1 -= 1
            count2 -= 1

    # After finding potential candidates, count their occurrences
    count1, count2 = 0, 0
    for num in nums:
        if num == candidate1:
            count1 += 1
        elif num == candidate2:
            count2 += 1

    n = len(nums)
    result = []

    # Verify candidates and add to the result
    if count1 > n // 3:
        result.append(candidate1)
    if count2 > n // 3:
        result.append(candidate2)

    return result

# Example usage:
nums1 = [3, 2, 3]
nums2 = [1]
nums3 = [1, 2]

output1 = majority_elements(nums1)
output2 = majority_elements(nums2)
output3 = majority_elements(nums3)

print(output1)  
print(output2) 
print(output3) 

